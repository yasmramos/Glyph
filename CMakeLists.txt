cmake_minimum_required(VERSION 3.20)
project(glyph LANGUAGES C CXX VERSION 0.1.0)

# ---------------------------------------------------------------------------
# Toolchain pins (see checklist §1): one LLVM, one ANTLR version everywhere.
# This sandbox has LLVM 23 + ANTLR runtime installed; CI uses the same
# versions so local and pipeline builds link against identical libraries.
set(GLYPH_LLVM_VERSION "23" CACHE STRING "LLVM major version to build against")
set(GLYPH_ANTLR_VERSION "4.13.1" CACHE STRING "ANTLR tool version (jar)")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  # Debug builds of LLVM consumers link extremely slowly; RelWithDebInfo is
  # the default for development.
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "" FORCE)
endif()

# On multi-version installs (e.g. apt.llvm.org packages under /usr/lib/llvm-N)
# CMake does not know where LLVM's Config files live, so point it at the
# version-prefixed prefix before the search.
# LLVM's Config version check is exact-match, so pass the full version when
# we already know it (e.g. llvm-config --version reports "23.1.5").
set(GLYPH_LLVM_FIND_VERSION "${GLYPH_LLVM_VERSION}")
if(NOT LLVM_DIR)
  find_file(GLYPH_LLVM_CONFIG_EXECUTABLE
    NAMES llvm-config-${GLYPH_LLVM_VERSION} llvm-config
    PATHS /usr/lib/llvm-${GLYPH_LLVM_VERSION}/bin /usr/bin /usr/local/bin)
  if(GLYPH_LLVM_CONFIG_EXECUTABLE)
    execute_process(COMMAND "${GLYPH_LLVM_CONFIG_EXECUTABLE}" --cmakedir
      OUTPUT_VARIABLE GLYPH_LLVM_CMAKE_DIR
      OUTPUT_STRIP_TRAILING_WHITESPACE)
    execute_process(COMMAND "${GLYPH_LLVM_CONFIG_EXECUTABLE}" --version
      OUTPUT_VARIABLE GLYPH_LLVM_FULL_VERSION
      OUTPUT_STRIP_TRAILING_WHITESPACE)
    cmake_path(GET GLYPH_LLVM_CMAKE_DIR PARENT_PATH GLYPH_LLVM_PREFIX)
    set(LLVM_DIR "${GLYPH_LLVM_CMAKE_DIR}" CACHE PATH "LLVM CMake config dir" FORCE)
    list(PREPEND CMAKE_PREFIX_PATH "${GLYPH_LLVM_PREFIX}")
    if(GLYPH_LLVM_FULL_VERSION)
      set(GLYPH_LLVM_FIND_VERSION "${GLYPH_LLVM_FULL_VERSION}")
    endif()
  endif()
endif()

find_package(LLVM "${GLYPH_LLVM_FIND_VERSION}" CONFIG REQUIRED)
if(NOT LLVM_PACKAGE_VERSION VERSION_GREATER_EQUAL GLYPH_LLVM_VERSION)
  message(FATAL_ERROR "Found LLVM ${LLVM_PACKAGE_VERSION}, but the project pins "
                      "LLVM ${GLYPH_LLVM_VERSION}")
endif()
message(STATUS "Using LLVM ${LLVM_PACKAGE_VERSION} from ${LLVM_DIR}")

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

add_definitions(${LLVM_DEFINITIONS})
include_directories(SYSTEM ${LLVM_INCLUDE_DIRS})
llvm_map_components_to_libnames(LLVM_LIBS
  core support irreader passes nativecodegen target mc x86dispatcher
  x86info asmparser)

# ANTLR C++ runtime: system package (Config verified in CI). The generated
# sources require 4.10+ APIs; the pinned system package provides them.
find_path(ANTLR4_INCLUDE_DIR antlr4-runtime.h PATHS /usr/include/antlr4-runtime)
find_library(ANTLR4_RUNTIME_LIB antlr4-runtime)
if(NOT ANTLR4_INCLUDE_DIR OR NOT ANTLR4_RUNTIME_LIB)
  message(FATAL_ERROR "ANTLR4 C++ runtime not found (install libantlr4-runtime-dev)")
endif()

# The sandbox ships runtime headers that do not include <any> themselves,
# while the ANTLR 4.13.1 tool generates visitors returning std::any. Force
# the include so generated code compiles against either header vintage.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include any")

# ---------------------------------------------------------------------------
# Generated parser library — kept separate so ANTLR-generated code is only
# recompiled when the grammar changes (checklist §10/§11 speed trap).
# ---------------------------------------------------------------------------
file(GLOB GENERATED_PARSER_SRCS ${CMAKE_SOURCE_DIR}/src/generated/*.cpp)
add_library(glyph_parser_gen STATIC ${GENERATED_PARSER_SRCS})
target_include_directories(glyph_parser_gen SYSTEM PUBLIC
  ${ANTLR4_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/src/generated)
target_link_libraries(glyph_parser_gen PUBLIC ${ANTLR4_RUNTIME_LIB})

# AST library: no LLVM, no ANTLR dependencies at all (checklist §3/§10).
add_library(glyph_ast STATIC src/ast/Ast.cpp)
target_include_directories(glyph_ast PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Parser front-end (AstBuilder) as its own static lib.
add_library(glyph_frontend STATIC src/parser/AstBuilder.cpp)
target_include_directories(glyph_frontend PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(glyph_frontend PUBLIC glyph_ast glyph_parser_gen)

# Codegen library.
add_library(glyph_codegen STATIC src/codegen/CodeGen.cpp)
target_include_directories(glyph_codegen PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(glyph_codegen PUBLIC glyph_ast ${LLVM_LIBS})

# Runtime library: compiled from C, linked into the driver so that the JIT
# path (repl/run in-process) resolves glyph_* symbols, and also built as a
# standalone static archive for the AOT path (`cc` linking of generated .o).
add_library(glyph_rt STATIC src/runtime/glyph_rt.c)
target_include_directories(glyph_rt PUBLIC ${CMAKE_SOURCE_DIR}/src/runtime)
set_target_properties(glyph_rt PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Driver.
add_executable(glyphc
  src/main.cpp
  src/runtime/Runtime.cpp)
target_include_directories(glyphc PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(glyphc PRIVATE
  glyph_frontend glyph_codegen glyph_ast glyph_rt ${LLVM_LIBS})

enable_testing()
add_subdirectory(tests)

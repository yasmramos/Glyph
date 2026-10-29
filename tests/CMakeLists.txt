# CTest wrapper around the shell runner so `ctest` works from any build dir.
add_test(NAME end_to_end
         COMMAND ${CMAKE_SOURCE_DIR}/tests/run-tests.sh)
set_tests_properties(end_to_end PROPERTIES
  ENVIRONMENT "GLYPHC=$<TARGET_FILE:glyphc>")

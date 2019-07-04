
cmake_minimum_required(VERSION 3.12)

if (NOT TEST_EXECUTABLE)
    message(FATAL_ERROR "TEST_EXECUTABLE must be defined!")
endif()



set(rel "${CMAKE_CURRENT_LIST_DIR}")

file(READ "${rel}/src/tdrake/mls_coroutines.hpp" MLS_COROUTINES_HPP)

file(READ "${rel}/src/tdrake/test.cpp" TEST_CPP)

execute_process(
    COMMAND "${TEST_EXECUTABLE}"
    OUTPUT_VARIABLE TEST_OUTPUT
)



configure_file("${rel}/README.md.in" "${rel}/README.md")


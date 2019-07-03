
cmake_minimum_required(VERSION 3.12)

add_executable(mls_coroutines
    src/mls_coroutines.hpp
    src/mls_coroutines.cpp
    src/test.cpp
)

# Generate README.md.
add_custom_command(
    TARGET mls_coroutines
    POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -DTEST_EXECUTABLE="$<TARGET_FILE:mls_coroutines>" -P README.cmake
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

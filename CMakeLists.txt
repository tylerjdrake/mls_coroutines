
cmake_minimum_required(VERSION 3.12)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)

    add_executable(mls_coroutines
        src/tdrake/mls_coroutines.hpp
        src/tdrake/mls_coroutines.cpp
        src/tdrake/test.cpp
    )

    # Generate README.md.
    add_custom_command(
        TARGET mls_coroutines
        POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -DTEST_EXECUTABLE="$<TARGET_FILE:mls_coroutines>" -P README.cmake
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    )

else()
    
    add_library(tdrake_mls_coroutines INTERFACE)
    target_include_directories(tdrake_mls_couroutines INTERFACE src)
    add_library(tdrake::mls_coroutines ALIAS tdrake_mls_coroutines)

endif()

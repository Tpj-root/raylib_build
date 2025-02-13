cmake_minimum_required(VERSION 3.10)

project(T4)

# Get absolute path of the project directory
set(LIB_HOME "${CMAKE_SOURCE_DIR}")

# Set raylib paths
set(RAYLIB_INCLUDE_DIR "${LIB_HOME}/raylib/include")
set(RAYLIB_LIB_DIR "${LIB_HOME}/raylib/libraylib.a")

# List of source files
set(EXAMPLES
    wall.c
)

# Loop through the examples and create an executable for each one
foreach(EXAMPLE ${EXAMPLES})
    get_filename_component(EXE_NAME ${EXAMPLE} NAME_WE)

    add_executable(${EXE_NAME} ${EXAMPLE})

    # Include Raylib
    target_include_directories(${EXE_NAME} PRIVATE ${RAYLIB_INCLUDE_DIR})

    # Link Raylib and required libraries
    target_link_libraries(${EXE_NAME} PRIVATE ${RAYLIB_LIB_DIR} -lGL -lm -lpthread -ldl -lX11)

    # Ensure resources folder is copied to build directory
    add_custom_command(
        TARGET ${EXE_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/resources
    )

    # Automatically run executable after build
    add_custom_command(
        TARGET ${EXE_NAME}
        POST_BUILD
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXE_NAME}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

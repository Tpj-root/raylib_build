cmake_minimum_required(VERSION 3.10)

project(T4)

#
# /home/cnc/Desktop/GIT_MAIN/raylib_build/help/raylib/libraylib.a
#

# Get absolute path of the project directory
#set(LIB_HOME "${CMAKE_SOURCE_DIR}")

# dir 
set(LIB_HOME "/home/cnc/Desktop/GIT_MAIN/raylib_build/help")
#

# Set raylib paths
set(RAYLIB_INCLUDE_DIR "${LIB_HOME}/raylib/include")
set(RAYLIB_LIB_DIR "${LIB_HOME}/raylib/libraylib.a")

# List of source files
set(EXAMPLES
    main.cpp
    core_3d_camera_free.cpp
    core_world_screen.c
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
        /home/cnc/Desktop/GIT_MAIN/raylib_build/help/resources
        ${CMAKE_BINARY_DIR}/resources
    )

    ## Automatically run executable after build
    #add_custom_command(
    #    TARGET ${EXE_NAME}
    #    POST_BUILD
    #    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXE_NAME}
    #    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    #)
endforeach()



# structs example source files
set(ST_EXAMPLES
    structs/structs_Vector2.cpp
)

# Loop through the examples and create an executable for each one
foreach(EXAMPLE ${ST_EXAMPLES})
    get_filename_component(EXE_NAME ${EXAMPLE} NAME_WE)

    add_executable(${EXE_NAME} ${EXAMPLE})

    # Include Raylib
    target_include_directories(${EXE_NAME} PRIVATE ${RAYLIB_INCLUDE_DIR})

    # Link Raylib and required libraries
    target_link_libraries(${EXE_NAME} PRIVATE ${RAYLIB_LIB_DIR} -lGL -lm -lpthread -ldl -lX11)
endforeach()
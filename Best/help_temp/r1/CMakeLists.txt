cmake_minimum_required(VERSION 3.10)

set(Project_name "RubiksCube")

project(${Project_name})

# Set Raylib home directory
set(LIB_HOME "/home/cnc/Desktop/Temp_3/raylib/build/")

# Set Raylib include and library paths
set(RAYLIB_INCLUDE_DIR "${LIB_HOME}/raylib/include")
set(RAYLIB_LIB_DIR "${LIB_HOME}/raylib")

# List of source files
set(SOURCES
	main.cpp
	RubiksCube.cpp
)

# Create executable
add_executable(${Project_name} ${SOURCES})

# Include Raylib headers
target_include_directories(${Project_name} PRIVATE ${RAYLIB_INCLUDE_DIR})

# Link Raylib and required libraries
target_link_directories(${Project_name} PRIVATE ${RAYLIB_LIB_DIR})
target_link_libraries(${Project_name} PRIVATE raylib GL m pthread dl X11)

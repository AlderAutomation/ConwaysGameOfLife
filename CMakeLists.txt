cmake_minimum_required(VERSION 3.10)
project(ConwayGOL)

# Define the source file
set(SOURCE_FILE ConwayGOL.cpp)

# Define extra sources 
set(EXTRA_SOURCES GOLWorld.cpp GOLWorld.h LifeForm.cpp LifeForm.h)

# Find the SFML library
find_package(SFML REQUIRED COMPONENTS graphics system window)

# Create an executable target
add_executable(ConwayGOL ${SOURCE_FILE} ${EXTRA_SOURCES})

# Link SFML libraries to Executable 
target_link_libraries(ConwayGOL ${SFML_LIBRARIES})
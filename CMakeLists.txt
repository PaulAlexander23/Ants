cmake_minimum_required(VERSION 2.6)
project(Ants)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(${PROJECT_NAME} src/main.cpp src/ant.cpp src/scent.cpp src/timer.cpp src/colony.cpp src/graphics.cpp src/zone.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

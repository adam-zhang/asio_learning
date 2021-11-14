cmake_minimum_required(VERSION 3.5)
project(client)
add_definitions(-W -Wall -std=c++11)

set(sources main.cpp)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} pthread)

cmake_minimum_required(VERSION 2.8)
project(sync_timer)
set(source main.cpp)
add_executable(${PROJECT_NAME} ${source})
target_link_libraries(${PROJECT_NAME} 
	boost_system
	pthread)

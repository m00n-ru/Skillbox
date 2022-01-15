cmake_minimum_required (VERSION 3.8)

add_executable (${PROJECT_NAME} main.cpp struct.cpp func.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
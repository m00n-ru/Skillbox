cmake_minimum_required (VERSION 3.8)

project (task3)


set(BUILD_CPR_TEST OFF)
set(CMAKE_USE_OPENSLL OFF)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335)
FetchContent_MakeAvailable(cpr)

add_executable (task3 task3.cpp)
target_link_libraries(task3 PRIVATE cpr::cpr)
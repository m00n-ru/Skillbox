cmake_minimum_required (VERSION 3.8)

project ("Computer" VERSION 1.0)

set(MAIN_DIRECTORY "src")
set(MAIN_SOURCE ${MAIN_DIRECTORY}/main.cpp
				${MAIN_DIRECTORY}/cpu/cpu.cpp
)

add_executable (${PROJECT_NAME} ${MAIN_SOURCE})

add_subdirectory (${MAIN_DIRECTORY}/gpu)
add_subdirectory (${MAIN_DIRECTORY}/kbd)
add_subdirectory (src/ram)

add_library(disk STATIC ${MAIN_DIRECTORY}/disk/disk.cpp)

set(SOURCE_LIB gpu
			   kbd
			   ram
			   disk
)

target_link_libraries(${PROJECT_NAME} ${SOURCE_LIB})	


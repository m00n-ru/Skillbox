cmake_minimum_required (VERSION 3.8)

set(CPP_LIST main.cpp
			 cpu.cpp
			 disk.cpp
			 gpu.cpp
			 kbd.cpp
			 ram.cpp
)

add_executable (${PROJECT_NAME} ${CPP_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
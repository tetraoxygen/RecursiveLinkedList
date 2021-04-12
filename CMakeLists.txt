cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(LinkedListRecursion)

add_executable(LinkedListRecursion src/LinkedListRecursion.cpp)

set_property(TARGET LinkedListRecursion PROPERTY CXX_STANDARD 14)

install(TARGETS LinkedListRecursion)

IF (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_link_libraries(LinkedListRecursion -static)
ENDIF()

if (MSVC)
	add_compile_options(/std:c++latest)
endif()
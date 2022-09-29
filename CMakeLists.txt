cmake_minimum_required (VERSION 3.10)
project (tree_trunks LANGUAGES CXX VERSION 0.1)

option(WITH_EXAMPLES	"compile tree trunks examples" OFF)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

if(WITH_EXAMPLES)
	include(examples/examples.cmake)
endif()

cmake_minimum_required (VERSION 3.10)
project (tree_trunks LANGUAGES CXX VERSION 0.1)

option(WITH_EXAMPLES	"compile tree trunks examples" OFF)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

if(MSVC)
	set(CMAKE_CXX_FLAGS "/W4 /EHsc")
	set(CMAKE_CXX_FLAGS_RELEASE "/O2")
else()
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-parameter -pedantic") 
	set(CMAKE_CXX_FLAGS_DEBUG "-g")
	set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include) 

if(NOT WITH_EXAMPLES)
	return()
endif()

set(EXAMPLES_DIR "examples")
set(EXAMPLES "tt_default" "custom_config" "custom_type" "modules" "eol" "enable_if")
set(OUTPUT_DIR "examples")

foreach(example ${EXAMPLES})
	add_executable(${example} ${EXAMPLES_DIR}/${example}.cpp)
	set_target_properties(${example} PROPERTIES
	    CXX_STANDARD 17
	    CXX_STANDARD_REQUIRED ON
	    CXX_EXTENSIONS OFF
	    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
	target_link_libraries(${example} ${PROJECT_NAME})
endforeach()

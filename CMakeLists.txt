cmake_minimum_required (VERSION 3.10)
project (tree_trunks)

unset(example_file CACHE)

if(NOT DEFINED example)
	message(FATAL_ERROR 
	"You must define a example [cmake -Dexample=<tt_default|custom_config|custom_type|modules|eol> ..")
endif()

message("Example: " ${example})

if(${example} STREQUAL "custom_config"
	OR ${example} STREQUAL custom_type
	OR ${example} STREQUAL modules
	OR ${example} STREQUAL tt_default
	OR ${example} STREQUAL eol)
	message(STATUS "Example " ${example})
	set(example_file ${example})
endif()

unset(example CACHE)

if(NOT DEFINED example_file)
	message(FATAL_ERROR 
	"You must define a example [cmake -Dexample=<tt_default|custom_config|custom_type|modules|eol> ..")
endif()

message(STATUS "Building OS: " ${CMAKE_SYSTEM_NAME})

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

message("Builder type: " ${CMAKE_BUILD_TYPE}) 

if(MSVC)
	message(STATUS "MSVC build")
	set(CMAKE_CXX_FLAGS "/W4 /std:c++17 /EHsc /bigobj")
	set(CMAKE_CXX_FLAGS_RELEASE "/O2")
else()
	message(STATUS "NO MSVC build")
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-parameter") 
	set(CMAKE_CXX_FLAGS_DEBUG "-g")
	set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

if(WIN32)
    macro(get_WIN32_WINNT version)
        if(CMAKE_SYSTEM_VERSION)
            set(ver ${CMAKE_SYSTEM_VERSION})
            string(REGEX MATCH "^([0-9]+).([0-9])" ver ${ver})
            string(REGEX MATCH "^([0-9]+)" verMajor ${ver})
            # Check for Windows 10, b/c we'll need to convert to hex 'A'.
            if("${verMajor}" MATCHES "10")
                set(verMajor "A")
                string(REGEX REPLACE "^([0-9]+)" ${verMajor} ver ${ver})
            endif()
            # Remove all remaining '.' characters.
            string(REPLACE "." "" ver ${ver})
            # Prepend each digit with a zero.
            string(REGEX REPLACE "([0-9A-Z])" "0\\1" ver ${ver})
            set(${version} "0x${ver}")
        endif()
    endmacro()

    get_WIN32_WINNT(ver)
    add_definitions(-D_WIN32_WINNT=${ver})
        message("WIN32: " ${ver})
endif()

message(STATUS "Compiler: " ${CMAKE_CXX_COMPILER_ID} " " ${CMAKE_CXX_COMPILER_VERSION})

set(MAIN_SRC ./examples/${example_file}.cpp)

add_executable(${example_file} ${MAIN_SRC})
set_target_properties(${example_file} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

include_directories(./src/include)


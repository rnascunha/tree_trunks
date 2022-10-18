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
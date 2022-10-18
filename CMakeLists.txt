cmake_minimum_required (VERSION 3.10)
project (tree_trunks LANGUAGES CXX VERSION 0.1)

option(WITH_EXAMPLES	"compile tree trunks examples" OFF)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE 
							$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
							$<INSTALL_INTERFACE:include>)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

#########################
# Examples				#
#########################

if(WITH_EXAMPLES)
	include(examples/examples.cmake)
endif()

#########################
# Install				#
#########################
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)

install(TARGETS ${PROJECT_NAME}
		EXPORT "${PROJECT_NAME}Targets"
		PUBLIC_HEADER DESTINATION include)

set(INSTALL_FILES "lib/cmake/${PROJECT_NAME}")

configure_package_config_file(
	"${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	INSTALL_DESTINATION ${INSTALL_FILES})

install(EXPORT "${PROJECT_NAME}Targets" 
		DESTINATION ${INSTALL_FILES}
		NAMESPACE ${PROJECT_NAME}::)
install(FILES 	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
				"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
			DESTINATION ${INSTALL_FILES})
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)

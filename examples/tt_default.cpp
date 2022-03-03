/**
 * This example is to use Tree Trunks out of the box.
 */

#include <cstdio> //printf

/**
 * Uncomment any of the lines below to change the default behaviour
 * All this macros must be declared before #include "tt/tt.hpp"
 */
//#define TT_USE_COLOR 				false	///< Will remove any color settings
//#define TT_USE_TIME				false	///< Will remove time output at log
//#define TT_USE_MODULE				false	///< Will show the module name (if present) at output
//#define TT_IGNORE_MODULE_LEVEL	true	///< Will ignore any module max level setting
//#define TT_USE_LOG_NAME			true	///< Will print the log name ("DEBUG", "STATUS", "WARNING"...)
//#define TT_USE_SHORT_LOG_NAME		false	///< Will not print short log name ("DEBG", "STAT", "WARN" ...)
//#define TT_NAME					"MyLog"	///< Will set a name to the default configuration

/**
 * Uncommeting one of the lines below.
 * This will set the global log level. Any messages at higher level will be ignored (not even compiled)
 * For example: if you set the level to "deprecated", messages level "status", "debug" and "none" will
 * be removed. ("none" is never showed, even if you set the level to "none").
 */
//#define TT_LEVEL type::none
//#define TT_LEVEL type::error
//#define TT_LEVEL type::warning
//#define TT_LEVEL type::deprecated
//#define TT_LEVEL type::status			///< default
//#define TT_LEVEL type::debug

#include "tt/tt.hpp"

/**
 * Definition of a module:
 * *

 * nothing change.
 */
static constexpr const tt::module example_mod = {
	/*.name 		= */"example", 			///< name of the module to output
	/*.max_level 	= */tt::type::status,	///< restrict module log level (if higher than the global, will have no efect
											///< just checked if TT_IGNORE_MODULE_LEVEL == false
	/*.enable 		= */true				///< enable check of max_level
};

/**
 * Call main function
 */
int main()
{
	std::printf("Showing Tree trunks default configuration messages...\n");
	std::printf("-----------------------------------------------------\n");

	/**
	 * Call of the log functions (printf-like)
	 * \note The module ("example_mod") can be removed
	 */
	int i = 0;

	tt::debug(example_mod, "[%d] This is a DEBUG message", i++);
	tt::status(example_mod, "[%d] This is a STATUS message", i++);
	tt::deprecated(example_mod, "[%d] This is a DEPRECATED message", i++);
	tt::warning(example_mod, "[%d] This is a WARNING message", i++);
	tt::error(example_mod, "[%d] This is a ERROR message", i++);
	tt::none(example_mod, "[%d] This is a NONE message", i++);

	return EXIT_SUCCESS;
}


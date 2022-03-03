/**
 * This examples show the use of different modules, and the control level
 */

#include <cstdio> //printf

/**
 * If you uncomment the line below, all modules max_level will be ignored
 */
//#define TT_IGNORE_MODULE_LEVEL	true
#define TT_LEVEL type::debug

#include "tt/tt.hpp"

/**
 * Definition of modules, each one with it's own max_level
 */
static constexpr tt::module debug_mod = {
	/*.name 		= */"Debug Mod",
	/*.max_level 	= */tt::type::debug
};

static constexpr tt::module status_mod = {
	/*.name 		= */"Status Mod",
	/*.max_level 	= */tt::type::status
};

static constexpr tt::module deprecated_mod = {
	/*.name 		= */"Deprecated Mod",
	/*.max_level 	= */tt::type::deprecated
};

//This module will ignore deprecated messages
static constexpr tt::module warning_mod = {
	/*.name 		= */"Warning Mod",
	/*.max_level 	= */tt::type::warning
};

//This module will ignore deprecated messages
static constexpr tt::module error_mod = {
		/*.name 		= */"Error Mod",
	/*.max_level 	= */tt::type::error
};

/**
 * Main function call
 */
int main()
{
	std::printf("Showing Tree trunks module use...\n");
	std::printf("---------------------------------\n");

	/**
	 * Print of messages only modules that accept deprecated messages
	 * ("deprecated", "status" and "debug" levels) will be shown
	 */
	tt::deprecated(debug_mod, "This is a DEPRECATED message");
	tt::deprecated(status_mod, "This is a DEPRECATED message");
	tt::deprecated(deprecated_mod, "This is a DEPRECATED message");
	tt::deprecated(warning_mod, "This is a DEPRECATED message");
	tt::deprecated(error_mod, "This is a DEPRECATED message");

	return EXIT_SUCCESS;
}

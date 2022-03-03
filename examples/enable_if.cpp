/**
 * 'enable_if' is a way to call function or run random code just if
 * its at the enabled log level.
 */

#include <cstdio> //printf

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
 * Definition of modules, each one with it's own max_level
 */
static constexpr tt::module my_mod = {
	/*.name 		= */"My Mod",
	/*.max_level 	= */tt::type::error
};

int main()
{
	std::printf("----------------------------\n");
	std::printf("Using enable_if functions...\n");
	std::printf("----------------------------\n");
	/**
	 * Calling a function
	 */
	tt::enable_if<tt::type::error>(std::printf, "this message error level %d/%d/%d\n", 1, 2, 3);
	/**
	 * Using with lambda
	 */
	tt::enable_if<tt::type::warning>([]{
		const char* pie = "my warming pie";
		std::printf("What pie? %s\n", pie);
	});

	tt::enable_if<tt::type::deprecated>(std::printf, "Deprecated\n");
	tt::enable_if<tt::type::status>(std::printf, "Status\n");
	tt::enable_if<tt::type::debug>(std::printf, "Debug\n");

	/**
	 * Using modules
	 */
	std::printf("-------------------------------\n");
	std::printf("Using enable_if with modules...\n");
	std::printf("-------------------------------\n");
	tt::enable_if<tt::type::error>(my_mod, std::printf, "Error\n");
	tt::enable_if<tt::type::warning>(my_mod, std::printf, "Warning\n");
	tt::enable_if<tt::type::deprecated>(my_mod, std::printf, "Deprecated\n");
	tt::enable_if<tt::type::status>(my_mod, std::printf, "Status\n");
	tt::enable_if<tt::type::debug>(my_mod, std::printf, "Debug\n");

	return 0;
}

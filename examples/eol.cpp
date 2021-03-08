/**
 * This example how to deal with end of line log. To it is presented a
 * new type:
 *
 *	enum class eol_type{
 *		none = 0,			///< No new line /No reset terminal color
 *		nl,					///< New line /No reset terminal color
 *		rs,					///< No new line/Reset terminal color
 *		nl_rs				///< New line/Reset terminal color
 *	};
 * When global config *.use_color=false*, any rs (reset terminal color) is ignored.
 */

#include <cstdio> //printf
#include "tt/tt.hpp"

/**
 * Call main function
 */
int main()
{
	std::printf("Showing Tree trunks EOL messages...\n");
	std::printf("-----------------------------------------------------\n");

	std::printf("Default EOL = nl_rs | new line / reset terminal color\n");
	tt::status("This line will reset color and break");
	tt::status<tt::eolt::nl_rs>("This line is the same of above");
	printf("This line must be uncolored\n");

	std::printf("\nEOL = nl | new line / No reset terminal color\n");
	tt::deprecated<tt::eolt::nl>("This line will break line, but terminal color will be keeped");
	std::printf("This line must be of the same color of above\n");
	/**
	 * Manually reset terminal color
	 */
	tt::rs();

	std::printf("\nEOL = rs | No new line / Reset terminal color\n");
	tt::warning<tt::eolt::rs>("This line will not break, but colors will be reset: ");
	std::printf("This line must be uncolored and at same line tha command above");
	/**
	 * Break line  (tt-style)
	 */
	tt::nl();

	std::printf("\nEOL = none | No new line / No reset terminal color\n");
	tt::error<tt::eolt::none>("This line won't break or unset colors: ");
	std::printf("Same line, same color!");
	/**
	 * Breaking line and unsetting colors
	 */
	tt::nl_rs();

	/***
	 * Coloring
	 */
	std::printf("\nTesting coloring...\n");
	tt::color<tt::type::none>();
	std::printf("Coloring ");
	tt::color<tt::type::error>();
	std::printf("based on ");
	tt::color<tt::type::warning>();
	std::printf("log level ");
	tt::color<tt::type::deprecated>();
	std::printf("and that's ");
	tt::color<tt::type::status>();
	std::printf("all folks");
	tt::color<tt::type::debug>();
	std::printf("!!!!");
	tt::nl_rs();

	return EXIT_SUCCESS;
}


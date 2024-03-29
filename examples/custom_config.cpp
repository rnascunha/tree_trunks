/**
 * This examples shows how to create you own color (and others) configuration,
 * using the default level.
 *
 * Here we are going to swap the foreground colors to the background of the
 * default configuration.
 *
 * Tip: check the tt/tt.hpp to see how the default configuration is defined.
 * You will see that its not much different... like a apple pie recipe
 */

#include <cstdio>	//printf
#include <utility>	//std::forward

#include "tt/types.hpp"
#include "tt/log.hpp"	//log<>
#include "tt/tt.hpp"	//default definition
//Must come after tt/tt.hpp otherwise all definition will be removed
#include "tt/color.hpp"	//Macro colors
/**
 * Optional: define a namespace to your configuration
 */
namespace Inverse{

/**
 * We are going to use the same level definition of the the default
 */
using type = tt::type;

/**
 * Definition of the output
 * As type::none doesn't have a definition, its always ignored
 */
static constexpr const Tree_Trunks::type_config<type> type_config[] = {
	//Level			//Long name		//Short name //Color definition
	{type::error, 		"ERROR", 		"ERRO",	BG_RED},
	{type::warning,		"WARNING", 		"WARN",	BG_YELLOW},
	{type::deprecated, 	"DEPRECATED", 	"DEPR",	BG_BRIG_YELLOW},
	{type::status, 		"STATUS", 		"STAT", BG_GREEN},
	{type::debug, 		"DEBUG", 		"DEBG",	BG_BLUE}
};

/**
 * Configuration
 */
static constexpr const Tree_Trunks::config<type> config = {
	/*.use_color 			= */true,			//Show (or not) colors
	/*.time 				= */true,			//Show (or not) timestamp
	/*.module 				= */true,			//Show (or not) module name (if present)
	/*.ignore_module_level = */true,		//Ignore (or not) modules level
	/*.log_name 			= */true,			//Show (or not) log name
	/*.log_sname 			= */false,		//Show (or not) short log name
	/*.name 				= */nullptr,		//Specify a name to the configuration (will be shown at the output)
	/*.max_level 			= */type::status,	//Define the configuration max_level
	/*.tp_config 			= */type_config	//The type configuration defined above
};

/**
 * Keep this name standard:
 * * log level=type;
 * * type_config<type>=type_config;
 * * config<type>=config.
 *
 * This way you can use the following header to create lots of convenient functions
 * to you. Check "tt/tt.hpp" header to examine other convenient definitions
 */
#include "tt/functions_conv.hpp"

}//Inverse

/**
 * Remove any color macro used
 */
#include "tt/uncolor.hpp"


/**
 * Calling the main function
 */
int main()
{
	std::printf("Showing Tree trunks custom config...\n");
	std::printf("------------------------------------\n");

	using namespace Inverse;

	//Logging...
	log<type::debug>("This is a DEBUG message");
	log<type::status>("This is a STATUS message");
	log<type::deprecated>("This is a DEPRECATED message");
	log<type::warning>("This is a WARNING message");
	log<type::error>("This is a ERROR message");
	log<type::none>("This is a NONE message");

	return EXIT_SUCCESS;
}

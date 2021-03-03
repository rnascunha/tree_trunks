/**
 * This examples shows how to create you own log levels, and configuring it.
 *
 * Tip: check the tt/tt.hpp to see how the default configuration is defined.
 * You will see that its not much different... like a apple pie recipe
 */
#include <cstdio>	//printf
#include <utility>	//std::forward

#include "tt/types.hpp"
#include "tt/log.hpp"	//log<>
#include "tt/color.hpp" //Macro colors

/**
 * Optional: define a namespace to your configuration
 */
namespace Spicy{

/**
 * Define the log levels that you want
 */
enum class type{
	red_chile = 0,
	carolina_reaper,
	cayenne,
	tabasco,
	chipotle,
	jalapeno,
	poblano,
};

/**
 * Definition of the output
 * As type::red_chile doesn't have a definition, its always ignored
 */
static constexpr const Tree_Trunks::type_config<type> type_config[] = {
	//Level					//Long name		//Short name //Color definition
	{type::carolina_reaper, "CAROLINE_REAPER", 	"CARE",	UNDERLINE ";" BLINK_SLOW ";" BG_BRIG_MAGENTA ";" FG_BRIG_WHITE},
	{type::cayenne,			"CAYENNE", 			"CAYN",	BLINK_SLOW ";" BG_BRIG_RED ";" FG_BRIG_WHITE},
	{type::tabasco, 		"TABASCO", 			"TABA",	BOLD ";" BG_BRIG_CYAN ";" FG_BRIG_WHITE},
	{type::chipotle, 		"CHIPOTLE", 		"CHIP", ITALIC ";" BG_BRIG_YELLOW ";" FG_BRIG_WHITE},
	{type::jalapeno, 		"JALAPENO", 		"JAPA",	BG_BRIG_GREEN ";" FG_BRIG_WHITE},
	{type::poblano, 		"POBLANO", 			"POBL",	STRIKE ";" BG_BRIG_BLUE ";" FG_BRIG_WHITE},
};

/**
 * Configuration log behavior
 */
static constexpr const Tree_Trunks::config<type> config = {
	.use_color 			= true,				//Show (or not) colors
	.time 				= true,				//Show (or not) timestamp
	.module 			= true,				//Show (or not) module name (if present)
	.ignore_module_level = true,			//Ignore (or not) modules level
	.log_name 			= true,				//Show (or not) log name
	.log_sname 			= false,			//Show (or not) short log name
	.name 				= nullptr,			//Specify a name to the configuration (will be shown at the output)
	.max_level 			= type::poblano,	//Define the configuration max_level
	.tp_config 			= type_config		//The type configuration defined above
};

/**
 * This is the function that will be used to call the log.
 * Check "tt/tt.hpp" to check other convenient definitions
 */
template<type MinType, typename ...Args>
constexpr std::size_t log(Args&& ... args) noexcept
{
	return Tree_Trunks::log<type, MinType, config>(std::forward<Args>(args)...);
}

}//Spicy

/**
 * Remove any color macro used
 */
#include "tt/uncolor.hpp"

int main()
{
	std::printf("Showing Tree trunks custom type...\n");
	std::printf("----------------------------------\n");

	using namespace Spicy;
	//Spicy logging...
	log<type::red_chile>("This is a RED CHILE spice");	//Ignored because doesn't have a definition
	log<type::poblano>("This is a POBLANO spice");
	log<type::jalapeno>("This is a JALAPENO spice");
	log<type::chipotle>("This is a CHIPOTLE spice");
	log<type::tabasco>("This is a TABASCO spice");
	log<type::cayenne>("This is a CAYENNE spice");
	log<type::carolina_reaper>("This is a CAROLINA REAPER spice");

	return EXIT_SUCCESS;
}

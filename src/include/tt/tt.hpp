#ifndef TREE_TRUNKS_DEFAULT_HPP__
#define TREE_TRUNKS_DEFAULT_HPP__

#include "types.hpp"
#include "log.hpp"
#include "color.hpp"

#include <utility>

#ifndef TT_LEVEL
#define TT_LEVEL	type::status
#endif /* TT_LEVEL */

#ifndef TT_USE_COLOR
#define TT_USE_COLOR 	true
#endif /* TT_USE_COLOR */

#ifndef TT_USE_TIME
#define TT_USE_TIME		true
#endif /* TT_USE_TIME */

#ifndef TT_USE_MODULE
#define TT_USE_MODULE	true
#endif /* TT_USE_TIME */

#ifndef TT_IGNORE_MODULE_LEVEL
#define TT_IGNORE_MODULE_LEVEL false
#endif /* TT_IGNORE_MODULE_LEVEL */

#ifndef TT_USE_LOG_NAME
#define TT_USE_LOG_NAME	false
#endif /* TT_USE_LOG_NAME */

#ifndef TT_USE_SHORT_LOG_NAME
#define TT_USE_SHORT_LOG_NAME true
#endif /* TT_USE_SHORT_LOG_NAME */

#ifndef TT_NAME
#define TT_NAME	nullptr
#endif /* TT_NAME */

/**
 * Convenience namespace
 */
namespace tt{

enum class type{
	none = 0,
	error,
	warning,
	deprecated,
	status,
	debug,
};

static constexpr Tree_Trunks::type_config<type> const type_config[] = {
	{type::error, 		"ERROR", 		"ERRO",	FG_RED},
	{type::warning, 	"WARNING", 		"WARN",	FG_YELLOW},
	{type::deprecated, 	"DEPRECATED", 	"DEPR",	FG_BRIG_YELLOW},
	{type::status, 		"STATUS", 		"STAT", FG_GREEN},
	{type::debug, 		"DEBUG", 		"DEBG",	FG_BLUE}
};

static constexpr const Tree_Trunks::config<type> config = {
	.use_color 				= TT_USE_COLOR,
	.time 					= TT_USE_TIME,
	.module 				= TT_USE_MODULE,
	.ignore_module_level 	= TT_IGNORE_MODULE_LEVEL,
	.log_name 				= TT_USE_LOG_NAME,
	.log_sname 				= TT_USE_SHORT_LOG_NAME,
	.name 					= TT_NAME,
	.max_level 				= TT_LEVEL,
	.tp_config 				= type_config
};

using module = Tree_Trunks::module<type>;
using eolt = Tree_Trunks::eol_type;

template<type MinType, eolt EOL = eolt::nl_rs, typename ...Args>
constexpr std::size_t log(Args&& ... args) noexcept
{
	return Tree_Trunks::log<type, MinType, config, EOL>(std::forward<Args>(args)...);
}

template<eolt EOL = eolt::nl_rs>
constexpr void eol()
{
	Tree_Trunks::eol<type, config, EOL>();
}

/**
 * Convenience functions
 */

template<eolt EOL = eolt::nl_rs, typename ...Args>
constexpr std::size_t debug(Args&& ... args) noexcept
{
	return log<type::debug, EOL>(std::forward<Args>(args)...);
}

template<eolt EOL = eolt::nl_rs, typename ...Args>
constexpr std::size_t status(Args&& ... args) noexcept
{
	return log<type::status, EOL>(std::forward<Args>(args)...);
}

template<eolt EOL = eolt::nl_rs, typename ...Args>
constexpr std::size_t deprecated(Args&& ... args) noexcept
{
	return log<type::deprecated, EOL>(std::forward<Args>(args)...);
}

template<eolt EOL = eolt::nl_rs, typename ...Args>
constexpr std::size_t warning(Args&& ... args) noexcept
{
	return log<type::warning, EOL>(std::forward<Args>(args)...);
}

template<eolt EOL = eolt::nl_rs, typename ...Args>
constexpr std::size_t error(Args&& ... args) noexcept
{
	return log<type::error, EOL>(std::forward<Args>(args)...);
}

template<eolt EOL = eolt::nl_rs, typename ...Args>
constexpr std::size_t none(Args&& ... args) noexcept
{
	return log<type::none, EOL>(std::forward<Args>(args)...);
}

template<typename ...Args>
constexpr void nl_rs(Args&&... args)
{
	eol<eolt::nl_rs>(std::forward<Args>(args)...);
}

template<typename ...Args>
constexpr void nl(Args&&... args)
{
	eol<eolt::nl>(std::forward<Args>(args)...);
}

template<typename ...Args>
constexpr void rs(Args&&... args)
{
	eol<eolt::rs>(std::forward<Args>(args)...);
}

}//tt

#include "uncolor.hpp"

#endif /* TREE_TRUNKS_DEFAULT_HPP__ */

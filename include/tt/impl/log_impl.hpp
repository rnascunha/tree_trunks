#ifndef TREE_TRUNKS_LOG_IMPL_HPP__
#define TREE_TRUNKS_LOG_IMPL_HPP__

#include "../log.hpp"
#include "../port.hpp"
#include <cstdarg>
#include <utility>

#if _MSC_VER
//Code unreacheble warning at some constexpr expressions
#pragma warning(push)
#pragma warning(disable: 4702)
#endif /* _MSC_VER */

namespace Tree_Trunks{

template<typename Type,
		Type LogType,
		config<Type> const& Config>
void color(FILE* stream) noexcept
{
	constexpr auto const* config = Config.get_type_config(LogType);
	if(config == nullptr) return;

	fprintf(stream, "\x1b[%sm", config->color);
}

template<typename Type,
		Type LogType,
		config<Type> const& Config>
void color() noexcept
{
	color<Type, LogType, Config>(stdout);
}

template<typename Type,
		config<Type> const& Config,
		eol_type EOL /* = eol_type::nl_rs */>
void eol(FILE* stream [[maybe_unused]]) noexcept
{
	if constexpr(EOL == eol_type::none) return;
	else if constexpr(EOL == eol_type::nl)
		fprintf(stream, "\n");
	else if constexpr(EOL == eol_type::rs)
	{
		if constexpr(Config.use_color)
			fprintf(stream, "\x1b[0m");
	}
	else if constexpr(EOL == eol_type::nl_rs)
	{
		if constexpr(Config.use_color)
			fprintf(stream, "\x1b[0m\n");
		else
			fprintf(stream, "\n");
	}
}

template<typename Type,
		config<Type> const& Config,
		eol_type EOL /* = eol_type::nl_rs */>
void eol() noexcept
{
	eol<Type, Config, EOL>(stdout);
}

template<typename Type,
		Type LogType,
		config<Type> const& Config,
		typename Func,
		typename ...Args>
void enable_if(module<Type> const& mod [[maybe_unused]], Func func, Args&&... args)
{
	if constexpr(LogType > Config.max_level) return;

	if constexpr(!Config.ignore_module_level)
		if (mod.enable && LogType > mod.max_level) return;

	func(std::forward<Args>(args)...);
}

template<typename Type,
		Type LogType,
		config<Type> const& Config,
		typename Func,
		typename ...Args>
void enable_if(Func func, Args&&... args)
{
	if constexpr(LogType > Config.max_level) return;

	func(std::forward<Args>(args)...);
}

template<typename Type,
		Type LogType,
		config<Type> const& Config,
		eol_type EOL /* = eol_type::nl_rs */>
std::size_t log(FILE* stream, module<Type> const& mod [[maybe_unused]], const char* format, va_list ap) noexcept
{
	if constexpr(LogType > Config.max_level) return 0;

	if constexpr(!Config.ignore_module_level)
		if (mod.enable && LogType > mod.max_level) return 0;

	constexpr auto const* config = Config.get_type_config(LogType);
	if(config == nullptr) return 0;

	std::size_t size = 0;
	if constexpr(Config.use_color) /*should count color chars?*/
		fprintf(stream, "\x1b[%sm", config->color);

	if constexpr(Config.time)
		size += fprintf(stream, time_str, static_cast<print_time_type>(time_func()));

	if constexpr(Config.name != nullptr)
		size += fprintf(stream, "|%s", Config.name);

	if constexpr(Config.module)
		if(mod.name)
			size += fprintf(stream, "|%s", mod.name);

	if constexpr(Config.log_name)
		if constexpr(config && config->name)
			size += fprintf(stream, "|%s", config->name);

	if constexpr(Config.log_sname)
		if constexpr(config && config->short_name)
			size += fprintf(stream, "|%s", config->short_name);

	size += fprintf(stream, ": ");
	size += vfprintf(stream, format, ap);

	eol<Type, Config, EOL>(stream);

	return size;
}

template<typename Type,
		Type LogType,
		config<Type> const& Config,
		eol_type EOL /* = eol_type::nl_rs */>
std::size_t log(FILE* stream, const char* format, ...) noexcept
{
	constexpr module<Type> mod = {/*.name = */nullptr, /*.max_level = */LogType , /*.enable = */false};

	va_list arglist;
	va_start(arglist, format);
	std::size_t size = log<Type, LogType, Config, EOL>(stream, mod, format, arglist);
	va_end(arglist);

	return size;
}

template<typename Type,
		Type LogType,
		config<Type> const& Config,
		eol_type EOL /* = eol_type::nl_rs */>
std::size_t log(module<Type> const& mod, const char* format, ...) noexcept
{
	va_list arglist;
	va_start(arglist, format);
	std::size_t size = log<Type, LogType, Config, EOL>(stdout, mod, format, arglist);
	va_end(arglist);

	return size;
}

template<typename Type,
		Type LogType,
		config<Type> const& Config,
		eol_type EOL /* = eol_type::nl_rs */>
std::size_t log(const char* format, ...) noexcept
{
	constexpr module<Type> mod = {/*.name = */nullptr, /*.max_level = */LogType , /*.enable = */false};

	va_list arglist;
	va_start(arglist, format);
	std::size_t size = log<Type, LogType, Config, EOL>(stdout, mod, format, arglist);
	va_end(arglist);

	return size;
}

}//Tree_Trunks

#if _MSC_VER
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TREE_TRUNKS_LOG_IMPL_HPP__ */

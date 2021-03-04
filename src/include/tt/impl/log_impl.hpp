#ifndef TREE_TRUNKS_LOG_IMPL_HPP__
#define TREE_TRUNKS_LOG_IMPL_HPP__

#include "../log.hpp"
#include "../port.hpp"
#include <cstdarg>

namespace Tree_Trunks{

template<typename Type,
		config<Type> const& Config,
		eol_type EOL = eol_type::nl_rs>
void eol(FILE* stream [[maybe_unused]]) noexcept
{
	if constexpr(EOL == eol_type::none) return;
	else if constexpr(EOL == eol_type::nl)
		fprintf(stream, "\n");
	else if constexpr(EOL == eol_type::rs)
	{
		if constexpr(Config.use_color)
			fprintf(stream, "\e[0m");
	}
	else if constexpr(EOL == eol_type::nl_rs)
	{
		if constexpr(Config.use_color)
			fprintf(stream, "\e[0m\n");
		else
			fprintf(stream, "\n");
	}
}

template<typename Type,
		config<Type> const& Config,
		eol_type EOL = eol_type::nl_rs>
void eol() noexcept
{
	eol<Type, Config, EOL>(stdout);
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
	if(!config) return 0;

	std::size_t size = 0;
	if constexpr(Config.use_color) /*should count color chars?*/
		size += fprintf(stream, "\e[%sm", config->color);

	if constexpr(Config.time)
		size += fprintf(stream, time_str, time_func());

	if constexpr(Config.name)
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
//	if constexpr(Config.use_color)
//		fprintf(stream, "\e[0m\n");
//	else
//		fprintf(stream, "\n");

	return size;
}

template<typename Type,
		Type LogType,
		config<Type> const& Config,
		eol_type EOL /* = eol_type::nl_rs */>
std::size_t log(FILE* stream, const char* format, ...) noexcept
{
	constexpr module<Type> mod = {.max_level = LogType , .enable = false};

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
	constexpr module<Type> mod = {.max_level = LogType , .enable = false};

	va_list arglist;
	va_start(arglist, format);
	std::size_t size = log<Type, LogType, Config, EOL>(stdout, mod, format, arglist);
	va_end(arglist);

	return size;
}

}//Tree_Trunks

#endif /* TREE_TRUNKS_LOG_IMPL_HPP__ */

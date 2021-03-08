#ifndef TREE_TRUNKS_LOG_HPP__
#define TREE_TRUNKS_LOG_HPP__

#include <cstdio>
#include <stdlib.h>
#include "types.hpp"

namespace Tree_Trunks{

template<typename Type,
		Type LogType,
		config<Type> const& Config>
void color(FILE* stream) noexcept;

template<typename Type,
		Type LogType,
		config<Type> const& Config>
void color() noexcept;

template<typename Type,
		config<Type> const& Config,
		eol_type EOL = eol_type::nl_rs>
void eol(FILE* stream) noexcept;

template<typename Type,
		config<Type> const& Config,
		eol_type EOL = eol_type::nl_rs>
void eol() noexcept;

template<typename Type,
		Type LogType,
		config<Type> const& Config,
		eol_type EOL = eol_type::nl_rs>
std::size_t log(FILE* stream, module<Type> const& mod, const char* format, ...) noexcept;

template<typename Type,
		Type LogType,
		config<Type> const& Config,
		eol_type EOL = eol_type::nl_rs>
std::size_t log(FILE* stream, const char* format, ...) noexcept;

template<typename Type,
		Type LogType,
		config<Type> const& Config,
		eol_type EOL = eol_type::nl_rs>
std::size_t log(module<Type> const* mod, const char* format, ...) noexcept;

template<typename Type,
		Type LogType,
		config<Type> const& Config,
		eol_type EOL = eol_type::nl_rs>
std::size_t log(const char* format, ...) noexcept;

}//Tree_Trunks

#include "impl/log_impl.hpp"

#endif /* TREE_TRUNKS_LOG_HPP__ */

#ifndef TREE_TRUNKS_LOG_HPP__
#define TREE_TRUNKS_LOG_HPP__

#include <stdlib.h>
#include "types.hpp"

namespace Tree_Trunks{

template<typename Type,
		Type LogType,
		unsigned N,
		config<Type, N> const& Config>
std::size_t log(FILE* stream, module<Type> const& mod, const char* format, ...) noexcept;

template<typename Type,
		Type LogType,
		unsigned N,
		config<Type, N> const& Config>
std::size_t log(FILE* stream, const char* format, ...) noexcept;

template<typename Type,
		Type LogType,
		unsigned N,
		config<Type, N> const& Config>
std::size_t log(module<Type> const* mod, const char* format, ...) noexcept;

template<typename Type,
		Type LogType,
		unsigned N,
		config<Type, N> const& Config>
std::size_t log(const char* format, ...) noexcept;

//template<typename Type,
//		Type LogType,
//		unsigned N,
//		config<Type, N> const& Config>
//std::size_t log(FILE* stream, const char* module_name, const char* format, ...) noexcept;
//
//template<typename Type,
//		Type LogType,
//		unsigned N,
//		config<Type, N> const& Config>
//std::size_t log(FILE* stream, const char* format, ...) noexcept;
//
//template<typename Type,
//		Type LogType,
//		unsigned N,
//		config<Type, N> const& Config>
//std::size_t log(const char* module_name, const char* format, ...) noexcept;
//
//template<typename Type,
//		Type LogType,
//		unsigned N,
//		config<Type, N> const& Config>
//std::size_t log(const char* format, ...) noexcept;

}//Tree_Trunks

#include "impl/log_impl.hpp"

#endif /* TREE_TRUNKS_LOG_HPP__ */

#ifndef TREE_TRUNKS_TYPES_HPP__
#define TREE_TRUNKS_TYPES_HPP__

#include "impl/meta_helper.hpp"

namespace Tree_Trunks{

template<typename Type>
struct type_config{
	Type		ltype;
	const char* name;
	const char* short_name;
	const char*	color;
};

template<typename Type>
struct config{
	bool			use_color = true;
	bool			time = true;
	bool			module = true;
	bool			ignore_module_level = false;
	bool			log_name = false;
	bool			log_sname = true;
	const char*		name = nullptr;
	Type			max_level;

	array_const<type_config<Type> const> const tp_config;

	constexpr type_config<Type> const* get_type_config(Type tc) const noexcept
	{
		for(unsigned i = 0; i < tp_config.size(); i++)
			if(tp_config[i]->ltype == tc) return tp_config[i];

		return nullptr;
	}
};

template<typename Type>
struct module{
	const char*	name = nullptr;
	Type 		max_level;
	bool		enable = true;
};

enum class eol_type{
	none = 0,			///< No new line /No reset terminal color
	nl,					///< New line /No reset terminal color
	rs,					///< No new line/Reset terminal color
	nl_rs				///< New line/Reset terminal color
};

}//Tree_Trunks

#endif /* TREE_TRUNKS_TYPES_HPP__ */

#ifndef TREE_TRUNKS_TYPES_HPP__
#define TREE_TRUNKS_TYPES_HPP__

namespace Tree_Trunks{

template<typename Type>
struct type_config{
	Type		ltype;
	const char* name;
	const char* short_name;
	const char*	color;
};

template<typename Type,
		unsigned N>
struct config{
	bool			use_color = true;
	bool			time = true;
	bool			module = true;
	bool			ignore_module_level = false;
	bool			log_name = false;
	bool			log_sname = true;
	const char*		name = nullptr;
	Type			max_level;

	type_config<Type> const (&tp_config)[N];

	constexpr unsigned size(){ return N; }

	constexpr type_config<Type> const* get_type_config(Type tc) const noexcept
	{
		for(unsigned i = 0; i < N; i++)
			if(tp_config[i].ltype == tc) return &tp_config[i];

		return nullptr;
	}
};

template<typename Type>
struct module{
	const char*	name = nullptr;
	Type 		max_level;
	bool		enable = true;
};

}//Tree_Trunks

#endif /* TREE_TRUNKS_TYPES_HPP__ */


using module = Tree_Trunks::module<type>;
using eolt = Tree_Trunks::eol_type;

template<type Type, eolt EOL = eolt::nl_rs, typename ...Args>
constexpr std::size_t log(Args&& ... args) noexcept
{
	return Tree_Trunks::log<type, Type, config, EOL>(std::forward<Args>(args)...);
}

template<eolt EOL = eolt::nl_rs>
constexpr void eol()
{
	Tree_Trunks::eol<type, config, EOL>();
}

template<type Type, typename ...Args>
constexpr void color(Args&& ...args) noexcept
{
	Tree_Trunks::color<type, Type, config>(std::forward<Args>(args)...);
}

template<typename ...Args>
constexpr void nl_rs(Args&&... args) noexcept
{
	eol<eolt::nl_rs>(std::forward<Args>(args)...);
}

template<typename ...Args>
constexpr void nl(Args&&... args) noexcept
{
	eol<eolt::nl>(std::forward<Args>(args)...);
}

template<typename ...Args>
constexpr void rs(Args&&... args) noexcept
{
	eol<eolt::rs>(std::forward<Args>(args)...);
}

template<type Type, typename ...Args>
constexpr void enable_if(Args&& ...args)
{
	Tree_Trunks::enable_if<type, Type, config>(std::forward<Args>(args)...);
}

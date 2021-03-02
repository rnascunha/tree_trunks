#ifndef TREE_TRUNKS_PORT_HPP__
#define TREE_TRUNKS_PORT_HPP__

#include <cstdio>
#include <ctime>

namespace Tree_Trunks{

using time_t = std::time_t;
static constexpr const char* time_str = "%lu";
auto const time_func = []{ return std::time(NULL); };

}//Tree_Trunks

#endif /* TREE_TRUNKS_PORT_HPP__ */

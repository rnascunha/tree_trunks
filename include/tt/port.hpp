#ifndef TREE_TRUNKS_PORT_HPP__
#define TREE_TRUNKS_PORT_HPP__

#include <cstdio>
#include <ctime>

namespace Tree_Trunks{

using time_t = std::time_t;
using print_time_type = long long unsigned;
static constexpr const char* time_str = "%llu";

inline time_t time_func() {
    return std::time(NULL);
}

}//Tree_Trunks

#endif /* TREE_TRUNKS_PORT_HPP__ */

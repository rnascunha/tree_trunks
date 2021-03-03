#ifndef TREE_TRUNKS_META_HELPER_HPP__
#define TREE_TRUNKS_META_HELPER_HPP__

#include <stdexcept>

namespace Tree_Trunks{

//https://stackoverflow.com/a/15863826
//https://stackoverflow.com/a/32287802
template<typename T>
class array_const{
    public:
        template<unsigned N>
        constexpr array_const(const T (&arr)[N])
            : arr_(arr), size_(N) {}

        constexpr unsigned size() const{ return size_; }
        constexpr T const* operator[](unsigned n) const
        {
        	return n < size_ ? &arr_[n] : throw std::out_of_range("");
        }
        constexpr const T* get() const { return arr_; }
    private:
        const T* arr_;
        const unsigned size_;
};

}//Tree_Trunks

#endif /* TREE_TRUNKS_META_HELPER_HPP__ */

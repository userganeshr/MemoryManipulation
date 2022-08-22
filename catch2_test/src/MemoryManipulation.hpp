#ifndef MEMORYMANIPULATION_HPP
#define MEMORYMANIPULATION_HPP

#include <cstring>
#include <array>

namespace vTitan {

    //! @brief  The function memCopy() is used to copy a specified number of bytes from one memory to another
    //! @param dest - Reference to the destination memory area where to write the data.
    //! @param src  - Reference to the source memory to read.
    //! For C array
    template<typename T, typename U, std::size_t d_size, std::size_t s_size>
    void memCopy(T (&dest)[d_size], U (&src)[s_size]){
        static_assert(s_size <= d_size , "Destination array size is too small can't perform memcpy!");
        memcpy(dest,src,sizeof(src));
    }

    //! For Std C++ array
    template <typename T,typename U, std::size_t d_size, std::size_t s_size> 
    void memCopy(std::array<T, d_size> &dest, std::array<U, s_size> &src)
    {
        static_assert(s_size <= d_size , "Destination array size is too small can't perform memcpy!");
        memcpy(&dest,&src,sizeof(src));
    }

    //! For Structure
    template <typename T> 
    void memCopy(T &dest, T &src)
    {
        memcpy(&dest,&src,sizeof(src));
    }

    //! @brief  The function memMove() is used to copy a specified number of bytes from one memory to another or to overlap on same memory.
    //! @param dest - Reference to the destination memory area where to write the data.
    //! @param src  - Reference to the source memory to read.
    //! For C array
    template<typename T, typename U, std::size_t d_size, std::size_t s_size>
    void memMove(T (&dest)[d_size], U (&src)[s_size]){
        static_assert(s_size <= d_size , "Destination array size is too small can't perform memmove!");
        memmove(dest,src,sizeof(src));
    }

    //! For Std C++ array
    template <typename T,typename U, std::size_t d_size, std::size_t s_size> 
    void memMove(std::array<T, d_size> &dest, std::array<U, s_size> &src)
    {
        static_assert(s_size <= d_size , "Destination array size is too small can't perform memmove!");
        memmove(&dest,&src,sizeof(src));
    }

    //! For Structure
    template <typename T> 
    void memMove(T &dest, T &src)
    {
        memmove(&dest,&src,sizeof(src));
    }

    //! @brief  The function memSet() is used to set all the bytes in a block of memory to a particular value.
    //! @param dest - Reference to the destination memory area where to write the data.
    //! @param src  - Reference to the source memory to read.
    template <typename T , typename U> 
    void memSet(T &dest, U src)
    {
        memset(&dest,src,sizeof(dest));
    }
}

#endif

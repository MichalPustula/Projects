#pragma once

#include <stdexcept>

template<typename T, size_t S>
class Array
{
public:
    constexpr size_t size() const { return S; }
    constexpr size_t max_size() const { return S; }

    constexpr bool empty() const { return false; }

    T& operator[](size_t index) { return m_data[index]; }
    const T& operator[](size_t index) const { return m_data[index]; }

    T& at(size_t index) 
    { 
        if (index < size()) {return m_data[index];}
        else {throw (std::out_of_range("Out of range"));}
    }
    const T& at(size_t index) const { return m_data[index]; }

private:
    T m_data[S];
};
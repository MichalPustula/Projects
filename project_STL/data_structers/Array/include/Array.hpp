#pragma once

template<typename T, size_t S>
class Array
{
public:
    constexpr int size() const
    {
        return S;
    }

    T& operator[](size_t index)
    {
        return m_Data[index];
    }

    const T& operator[](size_t index) const
    {
        return m_Data[index];
    }

private:
    T m_Data[S];
};
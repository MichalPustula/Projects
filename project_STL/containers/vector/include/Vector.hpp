#pragma once

template<typename T>
class Vector
{
public:
    Vector()
    {
        realloc(2);
    }

    // push_back(T data)
    // {

    // }

    size_t capacity()
    {
        return m_capacity;
    }
private:

void realloc(size_t new_capacity)
{
    T* new_block = new T[new_capacity];

    for (size_t i = 0; i < m_size; i++)
    {
    new_block[i] = m_data[i];
    }
    
    delete m_data;
    m_data = new_block;
    m_capacity = new_capacity;
}



private:
T* m_data = nullptr;

size_t m_size = 0;
size_t m_capacity = 0;
};

#pragma once

template<typename T>
class Vector
{
public:
    Vector()
    {
        realloc(2);
    }

    void push_back(const T& input)
    {
        if (m_size >= m_capacity)
        {
            realloc(m_capacity + m_capacity);
        }

        m_data[m_size] = input;
        m_size++;
    }

    void push_back(T&& input)
    {
        if (m_size >= m_capacity)
        {
            realloc(m_capacity + m_capacity);
        }

        m_data[m_size] = std::move(input);
        m_size++;
    }

    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }


    const T& operator[](size_t index) const
    {
        return m_data[index];
    }

    T& operator[](size_t index)
    {
        return m_data[index];
    }

private:

    void realloc(size_t new_capacity)
    {
        T* new_memory = new T[new_capacity];

        for (size_t i = 0; i < m_size; i++)
        {
            new (&new_memory[i]) T(std::move(m_data[i]));
        }
        
        delete[] m_data;
        m_data = new_memory;
        m_capacity = new_capacity;
    }

private:
    T* m_data = nullptr;

    size_t m_size = 0;
    size_t m_capacity = 0;
};

#pragma once

template <typename T>
class Unique_ptr
{
public:
    Unique_ptr(): m_data(nullptr) {}
    ~Unique_ptr() { if (m_data != nullptr) { delete m_data; } }

    Unique_ptr(T* input): m_data(input) {}  

    Unique_ptr(const Unique_ptr&) = delete;
    Unique_ptr& operator=(const Unique_ptr&) = delete;

    Unique_ptr(Unique_ptr&& input)
    {
        m_data = input.get();
        input.m_data = nullptr;
    }

    Unique_ptr& operator=(Unique_ptr&& input)
    {
        m_data = input.get();
        input.m_data = nullptr;
        return *this;
    }

    T* operator->() const { return m_data; }
    T& operator*() const { return *m_data; }

    T* get () const { return m_data; }

    T* release()
    {
        T* output;
        output = m_data;
        m_data = nullptr;
        return output;
    }

private:
    T* m_data;  
};  


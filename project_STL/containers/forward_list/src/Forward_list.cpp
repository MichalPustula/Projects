#include "../include/Forward_list.hpp"

Forward_list::Forward_list(): m_head{nullptr}{}
Forward_list::~Forward_list() 
{ 
    if (m_head != nullptr)
    {
        while(m_head->m_next != nullptr)
        {
            Node* temp = m_head;
            m_head = m_head->m_next;
            delete temp;
        }
        delete m_head;
    }
}

void Forward_list::push_front(int value)
{
    if (m_head == nullptr)
    {
        m_head = new Node(value);
        return;
    }
    
    Node* temp = new Node(value);
    temp->m_next = m_head;
    m_head = temp;
}

void Forward_list::pop_front()
{
    if(m_head == nullptr) {return;}
    if(m_head->m_next == nullptr)
    {
        delete m_head;
        m_head = nullptr;
        return; 
    }
    Node* temp = m_head;
    m_head = m_head->m_next;
    delete temp;
}


void Forward_list::reverse()
{
    if (m_head == nullptr) {return;}
    if (m_head->m_next == nullptr) {return;}
    
    Node* first = nullptr;
    Node* second = m_head;
    Node* third = nullptr;

    while (second != nullptr)
    {
        third = second->m_next;
        second->m_next = first;
        first = second;
        second = third;
    }
    m_head = first;
}

    
void Forward_list::print()
{
    if (m_head == nullptr)
    {
        std::cout << "Empty list\n";
        return;
    }
    m_head->print();
    std::cout << "\n";
}   


int& Forward_list::front() // problem: how to deal with "optional" 
// return value with basic data structers, cppref. says that 
//"calling front() on an empty container is undefined"
{
    return m_head->getData();
}




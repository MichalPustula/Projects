#include "../include/Node.hpp"

Node::Node(int data): m_next(nullptr), m_data(data) {}
Node::~Node() {}

int& Node::getData()
{
    return m_data;
}


void Node::print()
{
    std::cout << m_data << " ";
    if (m_next != nullptr)
    {
        m_next->print();
    }
}



#include "../include/Node.hpp"

#include <iostream>

Node::Node(int data): m_left(nullptr), m_right(nullptr), m_data(data)
{

}

Node::~Node()
{
    if (m_left != nullptr)  { delete m_left; }
    if (m_right != nullptr) { delete m_right; }
}

int Node::getData() const
{
    return m_data;
}

void Node::addNode(int val)
{
    if(val < m_data)
    {
        if (m_left == nullptr) {m_left = new Node(val);}
        else                   {m_left->addNode(val);}
    }
    else if(val > m_data)
    {
        if (m_right == nullptr) {m_right = new Node(val);}
        else                    {m_right->addNode(val);}
    }
    else
    {
        std::cout << "Value already added" << std::endl;
    }
}

int Node::depth() const 
{
    const int left_depth = m_left ? m_left->depth() : 0;
    const int right_depth = m_right ? m_right->depth() : 0;
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}
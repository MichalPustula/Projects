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

void Node::print(Node* node)
{
    if(node == nullptr) {return;}
    
    std::cout << "Data: " << m_data << '\n';

    if (m_left!= nullptr)
    {
        std::cout << "L";
        print(m_left);
    }

    if (m_right!= nullptr)
    {
        std::cout << "R";
        print(m_left);
    }
}

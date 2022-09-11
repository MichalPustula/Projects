#include "../include/Node.hpp"

Node::Node(int data): next{nullptr}, data{data} {}
Node::~Node() {}

int Node::getData() const
{
    return data;
}

void Node::addNode(int value) //problem: isn't it dumb to addNode at the end of list?
{
    if (next == nullptr)
    {
        next = new Node(value);
        return;
    }
    next->addNode(value);
}

void Node::print()
{
    std::cout << data << " ";
    if (next != nullptr)
    {
        next->print();
    }
}



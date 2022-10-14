#pragma once

#include "../include/Node.hpp"

#include <iostream>
#include <string>
 
class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    void insert(int val);
    int height();
    void print(const Node* node, bool isLeft, const std::string prefix);
    void print();

public:
Node* m_root;

private:

};


 


#include "../include/BinaryTree.hpp"

BinaryTree::BinaryTree(): m_root(nullptr)
{

}

BinaryTree::~BinaryTree() 
{ 
    delete m_root;
}

void BinaryTree::insert(int val)
{
    if(m_root == nullptr) {m_root = new Node(val);}
    else                  {m_root->addNode(val);}
}

void BinaryTree::printTree()
{
}
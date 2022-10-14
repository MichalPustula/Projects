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

int BinaryTree::height()
{
    if (m_root == nullptr) { return 0; }
    return m_root->depth();
}


void BinaryTree::print()
{
    print(m_root, false, "");    
}

void BinaryTree::print(const Node* node, bool isLeft, const std::string prefix)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        std::cout << node->getData() << std::endl;

        print(node->m_left, true, prefix + (isLeft ? "│   " : "    "));
        print(node->m_right, false, prefix + (isLeft ? "│   " : "    "));
    }
}
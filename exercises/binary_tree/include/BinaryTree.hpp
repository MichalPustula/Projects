#pragma once

#include "../include/Node.hpp"

#include <iostream>
 
class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    void insert(int val);
    void printTree();

public:
Node* m_root;

private:

};

 
// int maxDepth(Node* node)
// {
//     if (node == nullptr)
//         return -1;
//     else
//     {
//         /* compute the depth of each subtree */
//         int lDepth = maxDepth(node->left);
//         int rDepth = maxDepth(node->right);
     
//         /* use the larger one */
//         if (lDepth > rDepth) { return(lDepth + 1); }
//         else                 { return(rDepth + 1); } 
//     }
// }
 


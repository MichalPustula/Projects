#include "gtest/gtest.h"

#include "../include/BinaryTree.hpp"

TEST(BinaryTreeTests, printTree)
{
    BinaryTree binaryTree;

    binaryTree.insert(5);
    binaryTree.insert(2);
    binaryTree.insert(3);
    binaryTree.insert(6);
    binaryTree.insert(7);
    binaryTree.insert(8);

    binaryTree.printTree();
}

TEST(BinaryTreeTests, creatingEmptyContainerInsertingElementsToLeftBranch)
{
    BinaryTree binaryTree;

    binaryTree.insert(5);
    binaryTree.insert(4);
    binaryTree.insert(3);
    binaryTree.insert(2);

    EXPECT_EQ(binaryTree.m_root->m_left->m_left->getData(), 3);
    EXPECT_EQ(binaryTree.m_root->m_left->m_left->m_left->getData(), 2);
}

TEST(BinaryTreeTests, creatingEmptyContainerInsertingTheSameElementTwice)
{
    BinaryTree binaryTree;

    binaryTree.insert(5);
    binaryTree.insert(6);
    binaryTree.insert(6);

    EXPECT_EQ(binaryTree.m_root->m_right->getData(), 6);
}

TEST(BinaryTreeTests, creatingEmptyContainerInserting3Elements)
{
    BinaryTree binaryTree;

    binaryTree.insert(5);
    binaryTree.insert(4);
    binaryTree.insert(6);

    EXPECT_EQ(binaryTree.m_root->m_left->getData(), 4);
    EXPECT_EQ(binaryTree.m_root->m_right->getData(), 6);
}


TEST(BinaryTreeTests, creatingEmptyContainerInserting1Elements)
{
    BinaryTree binaryTree;

    binaryTree.insert(5);

    EXPECT_EQ(binaryTree.m_root->getData(), 5);
}
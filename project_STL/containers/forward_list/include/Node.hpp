#pragma once

#include <iostream>

class Node 
{
public:
    Node(int data);
    ~Node();
    
    int& getData();
    void print();
    
public:
Node* m_next{};
private:
int m_data{};

};
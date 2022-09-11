#pragma once

#include <iostream>

class Node 
{
public:
    Node(int data);
    ~Node();
    
    int getData() const;
    void addNode(int value);
    void print();
    
public:
Node* next;
private:
int data;

};
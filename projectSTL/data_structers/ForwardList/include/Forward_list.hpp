#pragma once

#include "../include/Node.hpp"

#include <iostream>

class Forward_list
{
public:
    Forward_list();
    ~Forward_list();

    void push_front(int value);
    void pop_front();
    void reverse();
    
    void print();  
    
    int front();

    Node* begin();

private:
    Node* head;
};
 
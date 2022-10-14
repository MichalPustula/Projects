#pragma once


class Node 
{
public:
    Node(int data);
    ~Node();
    
    int getData() const;
    void addNode(int val);
    int depth() const;
    
public:
    Node* m_left;
    Node* m_right;
    private:
    int m_data;

};

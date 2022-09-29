#pragma once


class Node 
{
public:
    Node(int data);
    ~Node();
    
    int getData() const;
    void addNode(int val);
    void print(Node* node);
    
public:
    Node* m_left;
    Node* m_right;
    private:
    int m_data;

};

/* Helper function that allocates a new Node with the
given data and NULL left and right pointers. */
// Node* newNode(int data)
// {
//     Node* Node = new Node(data);
//     Node->m_data = data;
//     Node->m_left = nullptr;
//     Node->m_right = nullptr;
     
//     return(Node);
// }
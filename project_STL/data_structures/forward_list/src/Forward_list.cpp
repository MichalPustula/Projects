#include "../include/Forward_list.hpp"

Forward_list::Forward_list(): head{nullptr}{}
Forward_list::~Forward_list() 
{ 
    if (head != nullptr)
    {
        while(head->next != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
    }
}

void Forward_list::push_front(int value)
{
    if (head == nullptr)
    {
        head = new Node(value);
        return;
    }
    
    Node* temp = new Node(value);
    temp->next = head;
    head = temp;
}

void Forward_list::pop_front()
{
    if(head == nullptr) {return;}
    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return; 
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}


void Forward_list::reverse()
{
    if (head == nullptr) {return;}
    if (head->next == nullptr) {return;}
    
    Node* first = nullptr;
    Node* second = head;
    Node* third = nullptr;

    while (second != nullptr)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    head = first;
}

    
void Forward_list::print()
{
    if (head == nullptr)
    {
        std::cout << "Empty list\n";
        return;
    }
    head->print();
    std::cout << "\n";
}   


int Forward_list::front() // problem: how to deal with "optional" 
// return value with basic data structers, cppref. says that 
//"calling front() on an empty container is undefined"
{
    if (head != nullptr) {return head->getData();}
    return 0;
}

Node* Forward_list::begin()
{
    return head;
}



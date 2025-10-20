#pragma once

#include <iostream>

struct Node
{
    Node* prev;
    Node* next;
    int value;
};

class DoubleLinkedList
{

public:
    void push_front(int _value);
    
    //void push_back(int value) {} //самостоятельно
    
    void pop_front();
    
    //void pop_back() {} //самостоятельно
    
    void insert(size_t position, int _value);
    
    //void erase(size_t position) {} //самостоятельно

    friend std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& list);

    private:
    Node* head;
    Node* tail;
    size_t size;
};
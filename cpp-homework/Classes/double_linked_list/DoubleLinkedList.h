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
    DoubleLinkedList(){}

    DoubleLinkedList(const DoubleLinkedList& _list): head(nullptr)
                                                   , tail(nullptr)
                                                   , size(0)
    {
        Node* current = _list.head;
        while(current!= _list.tail)
        {
            push_back(current->value);
            current = current->prev;
        }
        push_back(current->value);
    }

    DoubleLinkedList(std::initializer_list<int> lst): head(nullptr)
                                                    , tail(nullptr)
                                                    , size(0)
    {
        for(auto num: lst)
        {
            push_back(num);
        }
    }

    ~DoubleLinkedList()
    {
        Node* current = head;
        for (size_t i = 1; i < size; ++i)
        {
            current = current->prev;
            delete current->next;
        }
        delete current;
    }

    void push_front(int _value);
    
    void push_back(int _value);
    
    void pop_front();
    
    void pop_back();
    
    void insert(size_t position, int _value);
    
    void erase(size_t position);

    size_t get_size() const;

    DoubleLinkedList& operator=(const DoubleLinkedList& _list);

    friend std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& list);

private:
    Node* head=nullptr;
    Node* tail=nullptr;
    size_t size=0;
};
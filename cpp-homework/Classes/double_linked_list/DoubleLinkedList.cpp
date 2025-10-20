#include "DoubleLinkedList.h"

void DoubleLinkedList::push_front(int _value)
{
    Node* node = new Node();
    node->value = _value;
    
    if (head == nullptr)
    {
        tail = node;
    }
    else
    {
        head->next = node;
        node->prev = head;
    }
    head = node;
    size++;
}

void DoubleLinkedList::pop_front()
{
    head = head->prev;
    if (head != nullptr)
    {
        delete head->next;
        head->next = nullptr;
    }
    else
    {
        tail = head;
    }
    size--;
}

void DoubleLinkedList::insert(size_t position, int _value)
{
    if (position > size)
    {
        return;
    }
    
    if (position == 0)
    {
        push_front(_value);
        return;
    }
    /*
    if (position == size - 1)
    {
        push_back(_value);
        return;
    }*/
    
    Node* node = new Node();
    node->value = _value;
    
    Node* current = head;
    for (size_t i = 1; i < position; ++i)
    {
        current = current->prev;
    }
    
    Node* temp = current->next;
    current->next->prev = node;
    node->prev = current;
    current->next = node;
    node->next = temp;
}

std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& list)
{
    Node* current = list.head;
    for (size_t i = 1; i < list.size; ++i)
    {
        os<<current->value<<" ";
        current = current->prev;
    }
    return os;
}

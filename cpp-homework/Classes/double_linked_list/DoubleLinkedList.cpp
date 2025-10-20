#include "DoubleLinkedList.h"

#include <algorithm>

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

void DoubleLinkedList::push_back(int _value)
{
    Node* node = new Node();
    node->value = _value;
    if (head == nullptr)
    {
        head = node;
    }
    else
    {
        tail->prev = node;
        node->next = tail;
    }
    tail = node;
    size++;
}

void DoubleLinkedList::pop_back()
{
    if (head == nullptr) return;
    tail=tail->next;
    if (head != nullptr)
    {
        delete tail->prev;
        tail->prev = nullptr;
    }
    else
    {
        tail = head;
    }
    size--;
}

void DoubleLinkedList::pop_front()
{
    if(head==nullptr) return;
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
    if (position >= size)
    {
        return;
    }
    
    if (position == 0)
    {
        push_front(_value);
        return;
    } 
    if (position == size-1)
    {
        push_back(_value);
        return;
    }
    Node* node = new Node();
    node->value = _value;
    Node* current = head;
    for (size_t i = 0; i < position; ++i)
    {
        current = current->prev;
    }
    
    Node* temp = current->next;
    current->next->prev = node;
    node->prev = current;
    current->next = node;
    node->next = temp;
    size++;
}

void DoubleLinkedList::erase(size_t position)
{
    if (position >= size)
    {
        return;
    }
    
    if (position == 0)
    {
        pop_front();
        return;
    } 
    if (position == size - 1)
    {
        pop_back();
        return;
    }
    Node* current = head;
    for (size_t i = 0; i < position; ++i)
    {
        current = current->prev;
    }
    current->next->prev = current->prev;
    current->prev->next = current->next;
    delete current;
    size--;
}

size_t DoubleLinkedList::get_size() const
{
    return size;
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& _list)
{
    if(&_list == this) return *this;
    DoubleLinkedList copy_list(_list);
    std::swap(copy_list.head, head);
    std::swap(copy_list.tail, tail);
    std::swap(copy_list.size, size);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& list)
{
    if (list.head == nullptr) return os;
    Node* current = list.head;
    os<<"[";
    while(current!=list.tail)
    {
        os<<current->value<<",";
        current = current->prev;
    }
    os<<current->value<<"]";
    return os;
}

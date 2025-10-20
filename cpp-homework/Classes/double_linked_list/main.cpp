#include "DoubleLinkedList.h"

int main()
{
    DoubleLinkedList list;
    list.push_front(0);
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    std::cout<<list;
}
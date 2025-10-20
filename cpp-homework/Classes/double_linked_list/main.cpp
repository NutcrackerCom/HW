#include "DoubleLinkedList.h"

int main()
{
    DoubleLinkedList list;
    list.push_front(0);
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    DoubleLinkedList list2=list;
    DoubleLinkedList list3;
    DoubleLinkedList list4 = {1,2,3,4,5};
    list3 = list2;
    std::cout <<list2<<" "<< list2.get_size() <<"\n" ;
    std::cout <<list<<" "<< list.get_size() <<"\n";
    std::cout <<list3<<" "<< list3.get_size() <<"\n";
    std::cout <<list4<<" "<< list4.get_size() <<"\n";
}
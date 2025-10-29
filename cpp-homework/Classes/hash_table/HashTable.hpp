#include "HashTable.h"

template <class T>
void HashTable<T>::insert(T key)
{
    size_t index = std::hash<T>{}(key) % capacity;
    std::list<T>& l = table[index];
    for (T k : l)
    {
        if (k == key)
        {
            return;
        }
    }
    l.push_back(key);
    size++;
}


template <class T>
void HashTable<T>::erase(T key)
{
    size_t index = std::hash<T>{}(key) % capacity;
    std::list<T>& l = table[index];
    l.remove_if([key](const T& k){return k == key;});
}

template <class T>
bool HashTable<T>::count(T key)
{
    size_t index = std::hash<T>{}(key) % capacity;
    std::list<T>& l = table[index];
    for (T k : l)
    {
        if (k == key)
        {
            return true;
        }
    }
    return false;
}
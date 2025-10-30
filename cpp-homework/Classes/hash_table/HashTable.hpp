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
    size--;
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

template <class T>
HashTable<T>& HashTable<T>::operator=(const HashTable& table)
{
    if(&table == this) return *this;
    HashTable<T> _table(table);
    swap(_table);
    return *this;
}

template <class T>
bool HashTable<T>::operator==(const HashTable& table)
{
    if(table.table == *this.table) return true;
    else return false;
}

template <class T>
void HashTable<T>::swap(HashTable<T>& _table)
{
    std::swap(capacity, _table.capacity);
    std::swap(size, _table.size);
    std::swap(table, _table.table);
}
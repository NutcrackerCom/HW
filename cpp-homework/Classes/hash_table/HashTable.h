#pragma once

#include <vector>
#include <list>
#include <iostream>

template <class T>
class HashTable
{
public:
    HashTable<T>(size_t _capacity = 200): table(_capacity) {}

    HashTable<T>(const HashTable<T>& _table): capacity(_table.capacity)
                                            , table(_table.table)
                                            , size(_table.size){}

    void insert(T key);

    void erase(T key);

    bool count(T key);

    HashTable& operator=(const HashTable& table);

    bool operator==(const HashTable& table);

    ~HashTable() = default;

private:

    void swap(HashTable<T>& _table);

    size_t capacity = 200;
    std::vector<std::list<T>> table;
    size_t size = 0;
};

#include "HashTable.hpp"
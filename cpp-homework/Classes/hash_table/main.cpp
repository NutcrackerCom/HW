#include "HashTable.h"
#include <string>
int main()
{
    HashTable<int> table;
    table.insert(1);
    table.insert(201);
    std::cout<<table.count(201);
    table.erase(201);
    std::cout<<table.count(201);
    HashTable<int> table2(table);
    std::cout<<table.count(201);
    std::cout<<table.count(1);
}
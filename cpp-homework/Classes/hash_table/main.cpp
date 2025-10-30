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
    HashTable<int> table3;
    table3 = table2;
    std::cout<<table3.count(1);
    table.erase(1);
    std::cout<<table3.count(1);
    table2.erase(1);
    std::cout<<table3.count(1);
    table3.erase(1);
    std::cout<<table3.count(1);
}
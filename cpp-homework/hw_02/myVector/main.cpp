#include <iostream>
#include <string>
#include "Vector.h"

int main()
{
    Vector<std::string> v1 = {"a", "b"};
    Vector<std::string> v2 = {"c", "d"};
    //v2.push_back("e");
    //v2.insert(2, "x");
    //Vector<Vector<int>> v3 = {{1,2}, {3,4}};
    //std::cin >> v;
    std::cout << v2 << "\n"; //<< v3.get_size() <<"\n";
}
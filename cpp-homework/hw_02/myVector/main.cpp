#include <iostream>
#include <string>
#include "Vector.h"

int main()
{
    Vector<std::string> v1 = {"a", "b"};
    Vector<std::string> v2 = {"c", "d"};
    v2.push_back("e");
    v2.insert(2, "x");
    Vector< Vector<std::string> > v3 = {{"A"},{"s"}};
    Vector< Vector<std::string> > v4 = {v1, v2};
    v3.push_back(v1);
    //std::cin >> v;
    std::cout << v4 << "\n"; //<< v3.get_size() <<"\n";
}
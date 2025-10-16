#include <iostream>
#include "Vector.h"

int main()
{
    Vector v;
    std::cin >> v;
    std::cout << v << "\n" << v.get_size() << "\n";
}
#include <iostream>
#include "Vector.h"

int main()
{
    Vector v = {-1,0,1,2,3,4,5,6};
    Vector v1 = {-1,0,1,2,3,4,5,6};
    Vector v2 = {1,0,1,2,3,4,5,6};
    std::cout << (v == v2) << "\n";
    std::cout << (v == v1) << "\n";
    std::cout << v;
}
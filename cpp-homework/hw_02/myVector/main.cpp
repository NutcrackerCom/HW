#include <iostream>
#include "Vector.h"

int main()
{
    Vector v = {0,1,2,3,4,5,6};
    Vector v1 = {-1,-2,-3};
    Vector v2 = {0,1,2,3,4,5,6};
    v.insert(10, 100);
    //std::cout << v << "\n";
    //v2.erase(5,4);
    //v2=v1;
    std::cout << v << "\n";
}
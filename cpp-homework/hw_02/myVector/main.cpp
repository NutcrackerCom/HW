#include <iostream>
#include "Vector.h"

int main()
{
    Vector v = {-1,0,1,2,3,4,5,6};
    Vector v1 = {1,2,3};
    v1 = v;
    std::cout << v1<< "\n";
    v.erase(3);
    std::cout << v;
}
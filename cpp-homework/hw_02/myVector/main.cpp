#include <iostream>
#include "Vector.h"

int main()
{
    Vector v = {-1,0,1,2,3,4,5,6};
    Vector v2 = {1,0,1,2,3,4,5,6};
    //v = v2*10;
    v = v2 - v;
    std::cout << v;
}
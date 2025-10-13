#include "Complex.h"

#include<iostream>

int main()
{
    Complex c1(2,3);
    Complex c2(-1,1);
    //Complex c3 = c1;
    c1*=c2;

    std::cout<<c1;
}
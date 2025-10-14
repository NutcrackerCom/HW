#include "Complex.h"

#include<iostream>

int main()
{
    Complex c1(2,1);
    Complex c2(-2,1);
    Complex c3;

    std::cout<<(c1!=c2) << " c3 \n";
    std::cout<<c2 << " c2 \n";
    std::cout<<c1 << " c1 \n";
}
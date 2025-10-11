#include "String.h"

int main()
{
    String s = "Hello";
    String s2 = " world";
    s +=s2;
    String s3 = s;
    String s4 = s.copy(5, 3);
    std::cout << s4;
}
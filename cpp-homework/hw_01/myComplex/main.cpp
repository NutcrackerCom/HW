#include <iostream>

class Complex
{
public:
    Complex(){}
    Complex(double _re, double _im ): re(_re), im(_im) {}
    Complex(double _re): re(_re) {}

private:
    double re;
    double im;
};

int main()
{

}
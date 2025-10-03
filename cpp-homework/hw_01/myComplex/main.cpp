#include <iostream>

class Complex
{
public:
    Complex(){}
    Complex(double _re, double _im ): re(_re), im(_im) {}
    Complex(double _re): re(_re) {}

    Complex& operator=(const Complex& _comp)
    {
        if(&_comp == this) return *this;

        re = _comp.re;
        im = _comp.im;
        return *this;
    }

private:
    double re=0;
    double im=0;
};

int main()
{

}
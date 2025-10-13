#pragma once 

#include <iostream>

class Complex
{
public:
    Complex(){}
    Complex(double _re, double _im ): re(_re), im(_im) {}
    Complex(double _re): re(_re) {}
    Complex(const Complex& _complex): Complex(0,0)
    {
        re = _complex.re;
        im = _complex.im;
    };
    Complex& operator=(const Complex& _comp);

    Complex& operator+=(const Complex& other);

    Complex& operator-=(const Complex& other);

    Complex& operator*=(const Complex& other);

    Complex& operator+(const Complex& other);

    Complex& operator-(const Complex& other);

    bool operator==(const Complex& other);

    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);

private:
    double re=0;
    double im=0;
};

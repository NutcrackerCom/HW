#include "Complex.h"

Complex& Complex::operator=(const Complex& _comp)
{
    if(&_comp == this) return *this;

    re = _comp.re;
    im = _comp.im;
    return *this;
}

Complex& Complex::operator+=(const Complex& other)
{
    re+=other.re;
    im+=other.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
    re-=other.re;
    im-=other.im;
    return *this;
}

Complex& Complex::operator+(const Complex& other)
{
    *this+=other;
    return *this;
}

Complex& Complex::operator-(const Complex& other)
{
    *this-=other;
    return *this;
}

Complex& Complex::operator*=(const Complex& other)
{

    int _re = re*other.re - im*other.im;
    int _im = re*other.im + im*other.re;
    re = _re;
    im = _im;
    return *this;
}

bool Complex::operator==(const Complex& other)
{
    return (re==other.re)&&(im==other.im);
}

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
    os<<complex.re<<"+("<<complex.im<<"i)";
    return os;
}
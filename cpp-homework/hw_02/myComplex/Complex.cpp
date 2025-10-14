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

Complex& Complex::operator*=(const Complex& other)
{

    double _re = re*other.re - im*other.im;
    double _im = re*other.im + im*other.re;
    re = _re;
    im = _im;
    return *this;
}

Complex& Complex::operator*=(double num)
{
    re*=num;
    im*=num;
    return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
    double _re = (re*other.re + im*other.im)/(other.re*other.re + other.im*other.im);
    double _im = (other.re*im-re*other.im)/(other.re*other.re + other.im*other.im);
    re = _re;
    im = _im;
    return *this;
}

Complex& Complex::operator/=(double num)
{
    re/=num;
    im/=num;
    return *this;
}

Complex Complex::operator+(const Complex& other)
{
    Complex res(re, im);
    res+=other;
    return res;
}

Complex Complex::operator-(const Complex& other)
{
    Complex res(re, im);
    res-=other;
    return res;
}

Complex Complex::operator*(const Complex& other)
{
    Complex res(re, im);
    res*=other;
    return res;
}

Complex Complex::operator*(double num)
{
    Complex res(re, im);
    res*=num;
    return res;
}

Complex Complex::operator/(const Complex& other)
{
    Complex res(re, im);
    res/=other;
    return res;
}

Complex Complex::operator/(double num)
{
    Complex res(re, im);
    res/=num;
    return res;
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
#include "Circle.h"

double Circle::perimeter() const
{
    return 2*M_PI*radius;
}

double Circle::area() const
{
    return M_PI*radius*radius;
}

void Circle::get_description() const
{
    std::cout << "Circle\n";
    Shapes::get_description();
}
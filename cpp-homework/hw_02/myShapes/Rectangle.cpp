#include "Rectangle.h"

double Rectangle::perimeter() const
{
    return 2*A+2*B;
}

double Rectangle::area() const
{
    return A*B;
}

void Rectangle::get_description() const
{
    std::cout << "Rectangle\n";
    Shapes::get_description();
}
#include "Triangle.h"

bool Triangle::check_triangle() const
{
    return (A<=B+C)&&(B<=A+C)&&(C<=A+B);    
}

double Triangle::perimeter() const
{
    if(!check_triangle()) return -1;
    return A+B+C;
}

double Triangle::area() const
{
    if(!check_triangle()) return -1;
    double P = perimeter()/2;
    return sqrt(P*(P-A)*(P-B)*(P-C)); 
}

void Triangle::get_description() const
{
    std::cout << "Triangle\n";
    Shapes::get_description();
}

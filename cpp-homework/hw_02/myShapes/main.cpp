#include "Circle.h"
#include "Rectangle.h"
#include "Coordinates.h"
#include "Triangle.h"
int main()
{

    Rectangle r(2,3);
    r.get_description();

    Coordinates a{1,1};
    Coordinates b{1,4};
    Circle c(4);
    c.get_description();

    Triangle t(6,8,3);
    t.get_description();
    std::cout<< "len " <<Coordinates_func::get_len(a,b);


}
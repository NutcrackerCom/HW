#pragma once

#include <iostream>
#include <cmath>

#include "Shapes.h" 

class Circle : public Shapes
{
public:
    Circle(double _radius):radius(_radius){}

    double perimeter() const override;

    double area() const override;

    void get_description() const override;

private:
    double radius=0;
};
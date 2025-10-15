#pragma once

#include <iostream>
#include <cmath>

#include "Shapes.h" 
#include "Coordinates.h"

class Circle : public Shapes
{
public:
    Circle(double _radius, Coordinates _сenter = {0,0}):radius(_radius), 
                                               сenter{_сenter} {}

    double perimeter() const override;

    double area() const override;

    void get_description() const override;

private:
    double radius=0;

    Coordinates сenter{0,0};
};
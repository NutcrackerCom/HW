#pragma once

#include <iostream>
#include <cmath>

#include "Shapes.h"
#include "Coordinates.h"


class Triangle : public Shapes
{
public:
    Triangle(double _A, double _B, double _C): A(_A), B(_B), C(_C){}

    inline bool check_triangle() const;

    double perimeter() const override;

    double area() const override;

    void get_description() const override;

private:
    double A=0;
    double B=0;
    double C=0;
};
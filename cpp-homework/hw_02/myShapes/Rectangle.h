#pragma once

#include <iostream>

#include "Shapes.h"

class Rectangle : public Shapes
{
public:
    Rectangle(double _A, double _B): A(_A), B(_B){}

    double perimeter() const override;

    double area() const override;

    void get_description() const;

private:
    double A=0;
    double B=0;
};
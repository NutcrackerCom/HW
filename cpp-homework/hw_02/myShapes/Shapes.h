#pragma once

#include <iostream>

class Shapes
{
public:
    virtual double perimeter() const = 0;

    virtual double area() const = 0;

    virtual void get_description() const;
};
#pragma once

#include <iostream>
#include <cmath>

struct Coordinates
{
    int x;
    int y;
};

struct Coordinates_func
{
    static double get_len(Coordinates a, Coordinates b);
};

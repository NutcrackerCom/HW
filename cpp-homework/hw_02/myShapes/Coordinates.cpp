#include "Coordinates.h"

double Coordinates_func::get_len(Coordinates a, Coordinates b)
{
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
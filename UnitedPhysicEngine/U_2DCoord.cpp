#include "U_2DCoord.h"
#include <cmath>

U_2DCoord::U_2DCoord()
{
    x=0;
    y=0;
}

U_2DCoord::U_2DCoord(double x, double y)
{
    this->x = x;
    this->y = y;
}

void U_2DCoord::move2D(U_2DCoord& vec)
{
    this->x += vec.x;
    this->y += vec.y;
}

double U_2DCoord::getNorm()
{
    return sqrt(x*x+y*y);
}

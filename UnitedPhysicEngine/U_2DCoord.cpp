#include "U_2DCoord.h"

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

double U_2DCoord::dist2(U_2DCoord& u2dc)
{
    double d2;
    double vx, vy;

    vx = x-u2dc.x;
    vy = y-u2dc.y;

    d2 = vx*vx+vy*vy;

    return d2;
}

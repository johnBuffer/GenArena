#include "U_2DCoord.h"

bool operator==(U_2DCoord c1, U_2DCoord c2)
{
    return c1.x==c2.x&&c1.y==c2.y;
}

U_2DCoord operator+(U_2DCoord c1, U_2DCoord c2)
{
    return U_2DCoord(c1.x+c2.x, c1.y+c2.y);
}

U_2DCoord operator-(U_2DCoord c1, U_2DCoord c2)
{
    return U_2DCoord(c1.x-c2.x, c1.y-c2.y);
}

U_2DCoord operator*(double a, U_2DCoord c1)
{
    return U_2DCoord(c1.x*a, c1.y*a);
}

U_2DCoord operator*(U_2DCoord c1, U_2DCoord c2)
{
    return U_2DCoord(c1.x*c2.x, c1.y*c2.y);
}

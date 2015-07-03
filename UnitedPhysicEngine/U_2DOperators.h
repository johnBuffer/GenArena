#ifndef U_2DOPERATORS_H_INCLUDED
#define U_2DOPERATORS_H_INCLUDED

bool operator==(U_2DCoord c1, U_2DCoord c2);
U_2DCoord operator+(U_2DCoord c1, U_2DCoord c2);
U_2DCoord operator-(U_2DCoord c1, U_2DCoord c2);
U_2DCoord operator*(double a, U_2DCoord c1);
U_2DCoord operator*(U_2DCoord c1, U_2DCoord c2);

#endif // U_2DOPERATORS_H_INCLUDED

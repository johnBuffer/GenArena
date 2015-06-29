#ifndef U_2DCONSTRAINT_H_INCLUDED
#define U_2DCONSTRAINT_H_INCLUDED

#include "U_2DBody.h"
#include <cmath>

class U_2DConstraint
{
public:
    U_2DConstraint(U_2DBody* b1, U_2DBody* b2);
    U_2DConstraint(U_2DBody* b1, U_2DBody* b2, double length);
    void applyConstraint();

private:
    U_2DBody *m_body1, *m_body2;
    double m_length;

};

#endif // U_2DCONSTRAINT_H_INCLUDED

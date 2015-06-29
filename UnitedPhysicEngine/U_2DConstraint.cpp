#include "U_2DConstraint.h"

U_2DConstraint::U_2DConstraint(U_2DBody* b1, U_2DBody* b2)
{
    m_body1 = b1;
    m_body2 = b2;
}

U_2DConstraint::U_2DConstraint(U_2DBody* b1, U_2DBody* b2, double length)
{
    m_body1 = b1;
    m_body2 = b2;

    m_length = length;
}

void U_2DConstraint::applyConstraint()
{
    double vx = m_body1->getPosition().x-m_body2->getPosition().x;
    double vy = m_body1->getPosition().y-m_body2->getPosition().y;
    double dist = sqrt(vx*vx+vy*vy);
    double constraintForce = (dist-m_length)*0.5;

    vx *= constraintForce/dist;
    vy *= constraintForce/dist;

    m_body2->move2D(U_2DCoord(vx, vy));
    m_body1->move2D(U_2DCoord(-vx, -vy));
}

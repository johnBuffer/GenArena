#ifndef U_2DBODY_H_INCLUDED
#define U_2DBODY_H_INCLUDED

#include "U_2DCoord.h"

class U_2DBody
{
public:
    U_2DBody(U_2DCoord position, double mass);
    void move2D(U_2DCoord vec);
    void accelerate2D(U_2DCoord acc);
    void updatePosition(double timestep);
    void setX(double x) {m_position.x = x;};// m_lastPosition.x = x;};
    void setY(double y) {m_position.y = y;};// m_lastPosition.y = y;};
    U_2DCoord getPosition() const {return m_position;};
    void setStatic(bool isStatic) {m_static = isStatic;};
    bool isStatic() const {return m_static;};

private:
    U_2DCoord m_position, m_lastPosition, m_acceleration;
    double m_radius, m_mass;
    bool m_static;
};

#endif // U_2DBODY_H_INCLUDED

#include "U_2DBody.h"
#include "U_2DOperators.h"

U_2DBody::U_2DBody()
{
    m_position = U_2DCoord();
    m_lastPosition = U_2DCoord();
    m_mass = 1;
    m_acceleration = U_2DCoord();
    m_static = false;
}

U_2DBody::U_2DBody(U_2DCoord position, double mass)
{
    m_position = position;
    m_lastPosition = position;
    m_mass = mass;
    m_acceleration = U_2DCoord();
    m_static = false;
}

void U_2DBody::move2D(U_2DCoord vec)
{
    if (!m_static)
        m_position.move2D(vec);
}

void U_2DBody::accelerate2D(U_2DCoord vec)
{
    m_acceleration.move2D(vec);
}

void U_2DBody::updatePosition(double timeStep)
{
    U_2DCoord newPosition = 2*m_position-m_lastPosition+timeStep*m_acceleration;

    if (!m_static)
    {
        m_lastPosition = m_position;
        m_position = newPosition;
    }

    m_acceleration = U_2DCoord();
}


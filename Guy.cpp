#include "Guy.h"
#include "DisplayManager.h"
#include <cmath>

double DEG_TO_RAD = 0.0174532925;

Guy::Guy(U_2DBody* body)
{
    m_body = body;
    m_target = NULL;
    m_timeBeforeNewDirection = 0;
    m_follower = NULL;
}

void Guy::update()
{
    if (m_timeBeforeNewDirection) m_timeBeforeNewDirection--;

    if (!m_timeBeforeNewDirection)
    {
        m_body->stop();
        double angle = (rand()%360)*DEG_TO_RAD;
        m_body->accelerate2D(U_2DCoord(100*cos(angle), 100*sin(angle)));
        m_timeBeforeNewDirection = rand()%200+100;
    }

    if (m_target != NULL)
    {
        U_2DCoord direction = m_target->getPosition()-m_body->getPosition();
        direction = (100.0/direction.getNorm())*direction;
        m_body->stop();
        m_body->accelerate2D(direction);
    }

    if (m_follower != NULL)
    {
        m_follower->setOffset(-1*m_body->getPosition());
    }
}

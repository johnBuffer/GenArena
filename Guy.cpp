#include "Guy.h"

Guy::Guy(U_2DBody* body)
{
    m_body = body;
    m_timeBeforeNewDirection = 0;
}

void Guy::update()
{
    if (m_timeBeforeNewDirection) m_timeBeforeNewDirection--;
}

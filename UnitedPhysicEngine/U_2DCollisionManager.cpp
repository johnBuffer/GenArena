#include "U_2DCollisionManager.h"
#include <iostream>

U_2DCollisionManager::U_2DCollisionManager()
{
    m_timeStep = 1;
    m_bodySize = 1;
    m_mapSize = U_2DCoord();

    m_iterationCount = 0;

    m_gravity = U_2DCoord();
}

U_2DCollisionManager::U_2DCollisionManager(double timeStep, double bodyRadius, U_2DCoord mapSize)
{
    m_timeStep = timeStep;
    m_bodySize = bodyRadius*2;
    m_mapSize = mapSize;

    m_iterationCount = 2;

    m_gravity = U_2DCoord(0, 9.8);
}

U_2DBody* U_2DCollisionManager::addBody(U_2DCoord coord, double radius)
{
    U_2DBody* newBody = new U_2DBody(coord, radius);
    m_bodies.push_back(newBody);

    return newBody;
}

U_2DBody* U_2DCollisionManager::getBodyAt(int i)
{
    return m_bodies[i];
}

int U_2DCollisionManager::convertPosToHash(int x, int y)
{
    return x+y*1000000+100;
}

void U_2DCollisionManager::addBodyToGrid(U_2DBody* body)
{
    int bodyX = body->getPosition().x;
    int bodyY = body->getPosition().y;
    int caseSize = m_bodySize;
    int gridX = bodyX/caseSize;
    int gridY = bodyY/caseSize;
    int midGrid = caseSize/2;
    m_grid[convertPosToHash(gridX, gridY)].push_back(body);

    if (bodyX%caseSize > midGrid)
    {
        m_grid[convertPosToHash(gridX+1, gridY)].push_back(body);
        if (bodyY%caseSize > midGrid)
        {
            m_grid[convertPosToHash(gridX, gridY+1)].push_back(body);
            m_grid[convertPosToHash(gridX+1, gridY+1)].push_back(body);
        }
        else
        {
            m_grid[convertPosToHash(gridX, gridY-1)].push_back(body);
            m_grid[convertPosToHash(gridX+1, gridY-1)].push_back(body);
        }
    }
    else
    {
        m_grid[convertPosToHash(gridX-1, gridY)].push_back(body);
        if (bodyY%caseSize > midGrid)
        {
            m_grid[convertPosToHash(gridX-1, gridY+1)].push_back(body);
            m_grid[convertPosToHash(gridX, gridY+1)].push_back(body);
        }
        else
        {
            m_grid[convertPosToHash(gridX-1, gridY-1)].push_back(body);
            m_grid[convertPosToHash(gridX, gridY-1)].push_back(body);
        }
    }
}

void U_2DCollisionManager::applyGravity()
{
    int n_bodies = m_bodies.size();
    for (int i(0); i<n_bodies; ++i) m_bodies[i]->accelerate2D(m_gravity);
}

void U_2DCollisionManager::solveBoundCollisions(U_2DBody* body)
{
    int maxX = m_mapSize.x;
    int maxY = m_mapSize.y;
    int bodyX = body->getPosition().x;
    int bodyY = body->getPosition().y;

    int radius = m_bodySize/2;

    if (bodyY+radius > maxY-1) body->setY(maxY-1*radius);
    if (bodyX+radius > maxX-1) body->setX(maxX-1*radius);
    if (bodyY-radius < 0) body->setY(1*radius);
    if (bodyX-radius < 0) body->setX(1*radius);
}

void U_2DCollisionManager::solveGridCollisions(std::vector<U_2DBody*> bodies)
{
    int n_bodies = bodies.size();
    for (int i(0); i<n_bodies; ++i)
    {
        U_2DBody* currentBody = bodies[i];
        for (int k(i+1); k<n_bodies; k++)
        {
            U_2DBody* collider = bodies[k];
            m_nCollisionChecked++;

            double vx, vy;

            vx = currentBody->getPosition().x-collider->getPosition().x;
            vy = currentBody->getPosition().y-collider->getPosition().y;

            double dist2 = vx*vx+vy*vy;

            if (dist2 < m_bodySize*m_bodySize)
            {
                double dist = sqrt(dist2)+0.000001;
                double deltaDist = m_bodySize-dist;

                double coeff = 20;

                vx *= coeff*deltaDist/(dist)*m_timeStep;
                vy *= coeff*deltaDist/(dist)*m_timeStep;

                currentBody->move2D(U_2DCoord(vx, vy));
                collider->move2D(U_2DCoord(-vx, -vy));
            }
        }
    }
}

void U_2DCollisionManager::solveCollisions()
{
    m_grid.clear();
    int n_bodies = m_bodies.size();
    for (int i(0); i<n_bodies; ++i) addBodyToGrid(m_bodies[i]);

    std::map<int, std::vector<U_2DBody*> >::iterator it;
    for(it = m_grid.begin(); it != m_grid.end(); ++it) {
        solveGridCollisions((it->second));
    }

    for (int i(0); i<n_bodies; ++i) solveBoundCollisions(m_bodies[i]);
}

void U_2DCollisionManager::update()
{
    m_nCollisionChecked = 0;
    applyGravity();

    for (int i(0); i<m_iterationCount; ++i)
    {
        solveCollisions();
        solveConstraints();
        solveAttractions();
    }
    int n_bodies = m_bodies.size();
    for (int i(0); i<n_bodies; ++i) m_bodies[i]->updatePosition(m_timeStep);
}

void U_2DCollisionManager::solveConstraints()
{
    int n_constraints = m_constraints.size();
    for (int i=0; i<n_constraints; ++i) m_constraints[i]->applyConstraint();
}

void U_2DCollisionManager::addConstraint(U_2DBody* b1, U_2DBody* b2, double length)
{
    m_constraints.push_back(new U_2DConstraint(b1, b2, length));
}

void U_2DCollisionManager::addAttraction(U_2DBody* b1, U_2DBody* b2, double strength)
{
    m_attractions.push_back(new U_2DAttraction(b1, b2, strength));
}

void U_2DCollisionManager::solveAttractions()
{
    int n_attractions = m_attractions.size();
    for (int i=0; i<n_attractions; ++i) m_attractions[i]->applyAttraction();
}

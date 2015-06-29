#include "GameWorld.h"
#include <cstdlib>

double PI = 3.1415926;
int BIG_PI = 3141;
double DEG_TO_RAD = 0.0174532925;

GameWorld::GameWorld(U_2DCoord worldSize)
{
    m_GuyRadius = 30;
    m_collisionManager = U_2DCollisionManager(0.016, m_GuyRadius, worldSize);
    m_collisionManager.setGravity(U_2DCoord(0, 0));
    m_collisionManager.setPrecision(1);
    m_worldSize = worldSize;
    m_GuyCount = 0;
}

// add a new guy in the world
void GameWorld::addNewGuy(U_2DCoord position)
{
    m_GuyCount++;
    U_2DBody* newBody = m_collisionManager.addBody(position, 1);
    m_physicGuys.push_back(newBody);

    // add the first impulsion with a random angle
    double angle = (rand()%360)*DEG_TO_RAD;
    newBody->accelerate2D(U_2DCoord(100*cos(angle), 100*sin(angle)));
    m_guys.push_back(new Guy(newBody));
}

void GameWorld::updateGuys()
{
    for (int i(0); i<m_GuyCount; ++i)
    {
        m_guys[i]->update();
        if (m_guys[i]->needNewDirection())
        {
            m_physicGuys[i]->stop();
            double angle = (rand()%360)*DEG_TO_RAD;
            m_physicGuys[i]->accelerate2D(U_2DCoord(100*cos(angle), 100*sin(angle)));
            m_guys[i]->setNewDirection();
        }
    }
}

void GameWorld::update()
{
    updateGuys();
    m_collisionManager.update();
}

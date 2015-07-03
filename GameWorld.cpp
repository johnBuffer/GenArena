#include "GameWorld.h"
#include <cstdlib>

double PI = 3.1415926;
int BIG_PI = 3141;


GameWorld::GameWorld(U_2DCoord worldSize)
{
    m_GuyRadius = 30;
    m_collisionManager = U_2DCollisionManager(0.016, m_GuyRadius, worldSize);
    m_collisionManager.setGravity(U_2DCoord(0, 0));
    m_collisionManager.setPrecision(8);
    m_worldSize = worldSize;
    m_GuyCount = 0;
}

// add a new guy in the world
Guy* GameWorld::addNewGuy(U_2DCoord position)
{
    m_GuyCount++;
    U_2DBody* newBody = m_collisionManager.addBody(position, 1);
    m_physicGuys.push_back(newBody);

    // add the first impulsion with a random angle
    Guy* newGuy = new Guy(newBody);
    m_guys.push_back(newGuy);

    return newGuy;
}

void GameWorld::updateGuys()
{
    for (int i(0); i<m_GuyCount; ++i)
    {
        m_guys[i]->update();
    }
}

void GameWorld::update()
{
    updateGuys();
    m_collisionManager.update();
}

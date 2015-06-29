#include "GameWorld.h"

GameWorld::GameWorld(U_2DCoord worldSize)
{
    m_GuyRadius = 30;
    m_collisionManager = U_2DCollisionManager(0.016, m_GuyRadius, U_2DCoord(2000, 2000));
    m_collisionManager.setGravity(U_2DCoord(0, 0));
    m_collisionManager.setPrecision(3);

    m_GuyCount = 0;
}

void GameWorld::addNewGuy(U_2DCoord position)
{
    m_GuyCount++;
    U_2DBody* newBody = m_collisionManager.addBody(position, 1);
    m_physicGuys.push_back(newBody);
    m_guys.push_back(new Guy(newBody));
}

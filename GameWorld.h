#ifndef GAMEWORLD_H_INCLUDED
#define GAMEWORLD_H_INCLUDED

#include "UnitedPhysicEngine/U_2DCollisionManager.h"
#include "Guy.h"

class GameWorld
{
public:
    GameWorld(U_2DCoord worldSize);
    void update();

    void addNewGuy(U_2DCoord position);

    // accessors
    Guy* getGuyAt(int i) {return m_guys[i];};
    U_2DCoord getWorldSize() const {return m_worldSize;};
    int getGuyCount() const {return m_GuyCount;};
    int getGuyRadius() const {return m_GuyRadius;};

private:
    U_2DCollisionManager m_collisionManager;
    U_2DCoord m_worldSize;
    int m_GuyCount, m_GuyRadius;
    std::vector<Guy*> m_guys;
    std::vector<U_2DBody*> m_physicGuys;
    std::map<U_2DBody*, Guy*> m_GuyLinker;

};

#endif // GAMEWORLD_H_INCLUDED

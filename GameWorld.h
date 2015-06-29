#ifndef GAMEWORLD_H_INCLUDED
#define GAMEWORLD_H_INCLUDED

#include "UnitedPhysicEngine/U_2DCollisionManager.h"
#include "Guy.h"

class GameWorld
{
public:
    GameWorld(U_2DCoord worldSize);

    void addNewGuy(U_2DCoord position);


    Guy* getGuyAt(int i) {return m_guys[i];};

private:
    U_2DCollisionManager m_collisionManager;
    int m_GuyCount;
    std::vector<Guy*> m_guys;
    std::vector<U_2DBody*> m_physicGuys;
    std::map<U_2DBody*, Guy*> m_GuyLinker;

};

#endif // GAMEWORLD_H_INCLUDED
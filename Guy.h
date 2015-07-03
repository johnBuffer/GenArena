#ifndef GUY_H_INCLUDED
#define GUY_H_INCLUDED

#include "UnitedPhysicEngine/U_2DBody.h"
#include "UnitedPhysicEngine/U_2DOperators.h"

#include "Dna.h"

class DisplayManager;

class Guy
{
public:
    Guy(U_2DBody* body);

    U_2DBody* getBody() {return m_body;};
    bool needNewDirection() const {return m_timeBeforeNewDirection==0;};
    U_2DBody* getCollider();

    void setFollower(DisplayManager* dm) {m_follower = dm;};
    void stalk(Guy* guy) {m_target = guy->getBody();};
    void update();

private:
    int m_timeBeforeNewDirection;

    //ajouter DNA here
    Dna m_DNA;

    DisplayManager *m_follower;

    U_2DBody *m_body, *m_target;
};

#endif // GUY_H_INCLUDED

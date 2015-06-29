#ifndef GUY_H_INCLUDED
#define GUY_H_INCLUDED

#include "UnitedPhysicEngine/U_2DBody.h"
#include <vector>

class Guy
{
public:
    Guy(U_2DBody* body);

    U_2DBody* getBody() {return m_body;};

private:
    int m_dnaLength;

    //ajouter DNA here

    U_2DBody* m_body;
};

#endif // GUY_H_INCLUDED

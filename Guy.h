#ifndef GUY_H_INCLUDED
#define GUY_H_INCLUDED

#include "UnitedPhysicEngine/U_2DBody.h"
#include "Dna.h"

class Guy
{
public:
    Guy(U_2DBody* body);

    U_2DBody* getBody() {return m_body;};

private:
    int m_dnaLength;

    //ajouter DNA here
    Dna m_DNA;

    U_2DBody* m_body;
};

#endif // GUY_H_INCLUDED

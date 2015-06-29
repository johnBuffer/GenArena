#ifndef U_2DCOLISION_H_INCLUDED
#define U_2DCOLISION_H_INCLUDED

#include "U_2DBody.h"
#include "U_2DConstraint.h"

#include<map>
#include<vector>
#include<cmath>

class U_2DCollisionManager
{
public:
    U_2DCollisionManager();
    U_2DCollisionManager(double timeStep, double bodyRadius, U_2DCoord mapSize);
    U_2DBody* getBodyAt(int i);
    U_2DBody* addBody(U_2DCoord coord, double mass);

    void setGravity(U_2DCoord gravityVec) {m_gravity = gravityVec;};
    void setPrecision(unsigned int iterationCount) {m_iterationCount = iterationCount;};
    void addConstraint(U_2DBody* b1, U_2DBody* b2, double length);
    void killBody(U_2DBody* body);
    void update();

private:
    double m_timeStep, m_bodySize;
    int m_nCollisionChecked, m_iterationCount;
    U_2DCoord m_mapSize, m_gravity;
    std::vector<U_2DBody*> m_bodies;
    std::map<int, std::vector<U_2DBody*> > m_grid;
    std::vector<U_2DConstraint*> m_constraints;

    void addBodyToGrid(U_2DBody* body);
    int convertPosToHash(int x, int y);
    void applyGravity();
    void solveGridCollisions(std::vector<U_2DBody*> bodies);
    void solveCollisions();
    void solveBoundCollisions(U_2DBody* body);
    void solveConstraints();
};


#endif // U_2DCOLISION_H_INCLUDED

#ifndef DISPLAYMANAGER_H_INCLUDED
#define DISPLAYMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "GameWorld.h"
#include "UnitedPhysicEngine/U_2DBody.h"

class DisplayManager
{
public:
    DisplayManager(sf::RenderWindow *window, GameWorld *gameWorld);

    void draw();

private:
    GameWorld* m_GameWorld;
    sf::RenderWindow* m_window;

    double m_zoom, m_offsetX, m_offsetY;
};

#endif // DISPLAYMANAGER_H_INCLUDED

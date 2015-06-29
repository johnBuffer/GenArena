#ifndef DISPLAYMANAGER_H_INCLUDED
#define DISPLAYMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "GameWorld.h"

class DisplayManager
{
public:
    DisplayManager(sf::RenderWindow *window, GameWorld *gameWorld);

    void draw();

private:
    GameWorld* m_GameWorld;
    sf::RenderWindow* m_window;
};

#endif // DISPLAYMANAGER_H_INCLUDED

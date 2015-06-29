#include "DisplayManager.h"

DisplayManager::DisplayManager(sf::RenderWindow *window, GameWorld *gameWorld)
{
    m_window = window;
    m_GameWorld = gameWorld;

    m_zoom = 1;
    m_offsetX = 0;
    m_offsetY = 0;
}

void DisplayManager::draw()
{
    sf::CircleShape guy(m_GameWorld->getGuyRadius());
    int guyCount = m_GameWorld->getGuyCount();
    for (int i(0); i<guyCount; ++i)
    {

    }
}

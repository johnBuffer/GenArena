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
    sf::RectangleShape ground(sf::Vector2f(m_GameWorld->getWorldSize().x, m_GameWorld->getWorldSize().y));
    ground.setFillColor(sf::Color::Black);
    ground.setPosition(m_offsetX*m_zoom, m_offsetY*m_zoom);
    m_window->draw(ground);

    double radius = m_GameWorld->getGuyRadius()*m_zoom;
    sf::CircleShape guyRepresentation(radius);
    guyRepresentation.setOrigin(radius, radius);
    int guyCount = m_GameWorld->getGuyCount();
    for (int i(0); i<guyCount; ++i)
    {
        Guy* currentGuy = m_GameWorld->getGuyAt(i);
        U_2DBody* currentBody = currentGuy->getBody();

        double bodyX = currentBody->getPosition().x;
        double bodyY = currentBody->getPosition().y;

        guyRepresentation.setPosition((bodyX+m_offsetX)*m_zoom, (bodyY+m_offsetY)*m_zoom);
        m_window->draw(guyRepresentation);
    }
}

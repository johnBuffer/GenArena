#ifndef DISPLAYMANAGER_H_INCLUDED
#define DISPLAYMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "GameWorld.h"
#include "UnitedPhysicEngine/U_2DBody.h"

class DisplayManager
{
public:
    DisplayManager(sf::RenderWindow *window, GameWorld *gameWorld);

    //offset mutators
    void setOffset(double x, double y) {m_offsetX=x; m_offsetY=y;};
    void addOffset(double x, double y) {m_offsetX+=x/m_zoom; m_offsetY+=y/m_zoom;};

    // set the absolute zoom
    void setZoom(double zoom) {m_zoom = zoom;};

    // zoom on the current view (depending on the current zoom)
    void zoom(double zoomFactor) {m_zoom *= zoomFactor;};

    // draw the current gameWorld
    void draw();

private:
    GameWorld* m_GameWorld;
    sf::RenderWindow* m_window;

    double m_zoom, m_offsetX, m_offsetY;
};

#endif // DISPLAYMANAGER_H_INCLUDED

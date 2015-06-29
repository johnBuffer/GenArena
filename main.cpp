#include <SFML/Graphics.hpp>

#include "GameWorld.h"
#include "DisplayManager.h"

int main()
{
    double windowWidth = 750;
    double windowHeight = 500;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Genetic", sf::Style::Default);
    window.setVerticalSyncEnabled(false);
    window.setMouseCursorVisible(true);


    return 0;
}

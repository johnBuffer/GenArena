#include <SFML/Graphics.hpp>

#include "GameWorld.h"
#include "DisplayManager.h"

int main()
{
    srand(time(NULL));
    double windowWidth = 750;
    double windowHeight = 500;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Genetic", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    window.setMouseCursorVisible(true);

    GameWorld gameWorld(U_2DCoord(2000, 2000));
    gameWorld.addNewGuy(U_2DCoord(200, 200));

    DisplayManager displayManager(&window, &gameWorld);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			switch (event.type)
			{
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape) window.close();
                    break;
				default:
                    break;
			}
        }

        window.clear(sf::Color::White);

        gameWorld.update();
        displayManager.draw();

        window.display();
    }


    return 0;
}

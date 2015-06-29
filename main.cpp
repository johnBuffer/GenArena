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
    DisplayManager displayManager(&window, &gameWorld);

    // dragging
    bool mouseButtonPressed = false;
    sf::Vector2i dragClicPosition;

    // add a test guy
    gameWorld.addNewGuy(U_2DCoord(200, 200));

    // add more test guys
    for (int i(0); i<500; ++i) gameWorld.addNewGuy(U_2DCoord(rand()%2000, rand()%2000));

    while (window.isOpen())
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        sf::Event event;
        while (window.pollEvent(event))
        {
			switch (event.type)
			{
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape) window.close();
					else if ((event.key.code == sf::Keyboard::Subtract)) displayManager.zoom(0.8);
					else if ((event.key.code == sf::Keyboard::Add)) displayManager.zoom(1.2);
                    break;
                case sf::Event::MouseButtonPressed:
                    mouseButtonPressed = true;
                    dragClicPosition = mousePosition;
                    break;
                case sf::Event::MouseButtonReleased:
                    mouseButtonPressed = false;
                    break;
                case sf::Event::MouseMoved:
                    if (mouseButtonPressed) // in this case we are dragging
                    {
                        // updating displayManager offset
                        displayManager.addOffset(mousePosition.x-dragClicPosition.x, mousePosition.y-dragClicPosition.y);
                        dragClicPosition = mousePosition;
                    }
                    break;
                case sf::Event::Resized:
                    windowWidth = event.size.width;
                    windowHeight = event.size.height;

                    window.create(sf::VideoMode(windowWidth, windowHeight), "Genetic", sf::Style::Default, settings);
                    break;
				default:
                    break;
			}
        }

        window.clear(sf::Color::White);

        // #ObviousCodeForever
        gameWorld.update();
        displayManager.draw();

        window.display();
    }


    return 0;
}

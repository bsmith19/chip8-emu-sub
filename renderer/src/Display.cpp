#include "renderer/Display.h"
#include "SFML/Graphics/Rect.hpp"

const std::string WINDOW_TITLE = "Chip 8 Emulator";

Display::Display(int windowX, int windowY)
{
    mMemorySize = 0;
    pWindow = std::make_unique<sf::Window>(sf::VideoMode(windowX, windowY), WINDOW_TITLE);
    //pScreenBuffer = std::make_shared<sf::Vector2<int>>(new sf::Vector2<int>());
    sf::Vector2<int>();
}

Display::~Display()
{
}

bool Display::render_frame()
{
    if (pWindow->isOpen())
    {
        sf::Event event;
        while(pWindow->pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    pWindow->close();
                    break;
                    
                default:
                    break;
            }
        }
    }
}

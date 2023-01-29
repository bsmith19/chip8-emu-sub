#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <SFML/Window.hpp>

class Display
{
public:
    Display(int windowX, int windowY);
    ~Display();
    
    bool init();
    bool render_frame();
    
    
private:
    int mMemorySize;
    std::unique_ptr<sf::Window> pWindow;
    std::shared_ptr<sf::Vector2<int>> pScreenBuffer;
};

#endif

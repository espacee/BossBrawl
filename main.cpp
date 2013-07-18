#include <SFML/Graphics.hpp>

#include "StateManager.h"

int main()
{
    StateManager m;
    m.SetCurrentState(MENU);

    sf::RenderWindow w(sf::VideoMode(800, 600, 32), "Window");
    w.setFramerateLimit(60);

    while (m.GetCurrentState() != EXIT)
    {
        m.Loop(w);
    }

    return 0;
}

#include <SFML/Graphics.hpp>

#include "StateManager.hpp"
#include "config.hpp"

int main()
{
    StateManager m;
    m.SetCurrentState(MENU);
    config::Load();

    sf::RenderWindow w(sf::VideoMode(config::windowWidth, config::windowHeight, 32), "Window");
    w.setFramerateLimit(60);

    while (m.GetCurrentState() != EXIT)
    {
        m.Loop(w);
    }

    config::Save();
    return 0;
}

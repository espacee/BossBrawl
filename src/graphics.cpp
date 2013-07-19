#include "graphics.hpp"

#include "config.hpp"

namespace graphics
{

sf::RenderWindow window;

void Init()
{
    window.create(sf::VideoMode(config::windowWidth, config::windowHeight, 32), "Window");
    window.setFramerateLimit(60);
}

}

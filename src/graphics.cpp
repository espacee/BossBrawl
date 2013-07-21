#include "graphics.hpp"

#include "config.hpp"

namespace graphics
{

sf::RenderWindow window;
sf::Font font;

void Init()
{
    window.create(sf::VideoMode(config::windowWidth, config::windowHeight, 32), "Window");
    window.setFramerateLimit(60);

    font.loadFromFile("res/font/arial.ttf");
}

}

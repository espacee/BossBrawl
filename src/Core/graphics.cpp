#include "Core/graphics.hpp"

#include "Core/config.hpp"

namespace graphics
{

sf::RenderWindow window;
sf::Font font;

void init()
{
    window.create(sf::VideoMode(config::windowWidth, config::windowHeight, 32), "BossBrawl", sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    font.loadFromFile("res/font/arial.ttf");
}

}

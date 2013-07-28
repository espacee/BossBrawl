#include "Core/graphics.hpp"

#include "Core/config.hpp"

namespace graphics
{

sf::RenderWindow window;
sf::Font font;

std::string m_title;

void init()
{
    m_title = "BossBrawl";
    setResolution(config::windowWidth, config::windowHeight);
    window.setVerticalSyncEnabled(true);

    font.loadFromFile("res/font/arial.ttf");
}

void setResolution(int width, int height)
{
    window.create(sf::VideoMode(width, height), m_title, sf::Style::Close);
}

}

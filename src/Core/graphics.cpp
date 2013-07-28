#include "Core/graphics.hpp"

#include "Core/config.hpp"

#include <vector>

namespace graphics
{

sf::RenderWindow window;
sf::Font font;

std::string m_title;
std::vector<sf::Vector2i> m_resolutions = {
    {800, 600},
    {1000, 800},
    {1280, 720}
};

void init()
{
    m_title = "BossBrawl";
    setResolutionMode(config::resolutionMode);
    window.setVerticalSyncEnabled(true);

    font.loadFromFile("res/font/arial.ttf");
}

void setResolutionMode(int index)
{
    const sf::Vector2i& res = m_resolutions.at(index);
    window.create(sf::VideoMode(res.x, res.y), m_title, sf::Style::Close);
}

}

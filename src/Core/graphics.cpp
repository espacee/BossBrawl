#include "Core/graphics.hpp"

#include "Core/config.hpp"

#include <vector>
#include <iostream>

namespace graphics
{

sf::RenderWindow window;
sf::Font font;

std::string m_title;
std::vector<sf::Vector2i> m_resolutionModes = {
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

void setResolutionMode(unsigned int index)
{
    if (index >= m_resolutionModes.size())
    {
        std::cerr << "Warning: Non-existent resolution mode. Using smallest as fallback";
        index = 0;
    }

    const sf::Vector2i& res = m_resolutionModes.at(index);
    window.create(sf::VideoMode(res.x, res.y), m_title, sf::Style::Close);
}

const std::vector<sf::Vector2i>& getResolutionModes()
{
    return m_resolutionModes;
}



}

#include "Map/Layer.hpp"

Layer::Layer(const std::string &name) :
    m_name(name),
    m_visible(true),
    m_gridColor(sf::Color(0, 0, 0)),
    m_x(0), m_y(0),
    m_depthIndex(1.0f)
{
    resize(1, 1);
    fill(0);
}

void Layer::resize(unsigned int w, unsigned int h)
{
    if (w >= 1 && h >= 1)
    {
        m_tiles.resize(w);

        for (unsigned int i = 0; i < w; i++)
        {
            m_tiles[i].resize(h, 0);
        }
    }
}

void Layer::fill(unsigned int id)
{
    for (int i = 0; i < getHLength(); i++)
    {
        for (int j = 0; j < getVLength(); j++)
        {
            m_tiles[i][j] = id;
        }
    }
}

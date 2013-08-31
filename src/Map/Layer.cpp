#include "Map/Layer.hpp"

Layer::Layer(const std::string &name) :
    m_name(name)
{
    resize(1, 1);
    fill(0);
    m_x = m_y = 0;
    m_depthIndex = 1.f;
    m_visible = true;

    setGridColor(sf::Color(0, 0, 0));
}

void Layer::resize(unsigned int new_hLength, unsigned int new_vLength)
{
    if (new_hLength >= 1 && new_vLength >= 1)
    {
        m_tiles.resize(new_hLength);

        for (unsigned int i = 0; i < new_hLength; i++)
        {
            m_tiles[i].resize(new_vLength, 0);
        }
    }
}

void Layer::setTile(unsigned int x, unsigned int y, unsigned int id)
{
    if (tileExists(x, y))
        m_tiles[x][y] = id;
}

unsigned int Layer::getTile(unsigned int x, unsigned int y) const
{
    if (tileExists(x, y))
    {
        return m_tiles[x][y];
    }
    else
    {
        return 0;
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

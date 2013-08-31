#include "Map/Layer.hpp"

Layer::Layer(const std::string &name) :
    m_name(name)
{
    resize(1, 1);
    fill(0);
    x_coord = y_coord = 0;
    depthIndex = 1.f;
    visible = true;

    setGridColor(sf::Color(0, 0, 0));
}

void Layer::resize(unsigned int new_hLength, unsigned int new_vLength)
{
    if (new_hLength >= 1 && new_vLength >= 1)
    {
        map.resize(new_hLength);

        for (unsigned int i = 0; i < new_hLength; i++)
        {
            map[i].resize(new_vLength, 0);
        }
    }
}

void Layer::setTile(unsigned int x, unsigned int y, unsigned int id)
{
    if (tileExists(x, y))
        map[x][y] = id;
}

unsigned int Layer::getTile(unsigned int x, unsigned int y) const
{
    if (tileExists(x, y))
    {
        return map[x][y];
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
            map[i][j] = id;
        }
    }
}

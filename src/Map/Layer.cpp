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

void Layer::move(int x_offset, int y_offset)
{
    x_coord += x_offset;
    y_coord += y_offset;
}

void Layer::setPosition(int new_x_coord, int new_y_coord)
{
    x_coord = new_x_coord;
    y_coord = new_y_coord;
}

void Layer::setDepthIndex(float new_depthIndex)
{
    depthIndex = new_depthIndex;
}


int Layer::getX() const
{
    return x_coord;
}

int Layer::getY() const
{
    return y_coord;
}

sf::Vector2f Layer::getPosition()
{
    return sf::Vector2f(x_coord, y_coord);
}

float Layer::getDepthIndex()
{
    return depthIndex;
}

int Layer::getHLength() const
{
    return map.size();
}

int Layer::getVLength() const
{
    return (map.size() ? map[0].size() : 0);
}

int Layer::getWidth() const
{
    return getHLength() * GRID_SIZE;
}

int Layer::getHeight() const
{
    return getVLength() * GRID_SIZE;
}

void Layer::setGridColor(sf::Color new_gridColor)
{
    gridColor = sf::Color(new_gridColor.r, new_gridColor.g, new_gridColor.b);
}

sf::Color Layer::getGridColor() const
{
    return gridColor;
}

void Layer::setVisible(bool yesno)
{
    visible = yesno;
}

bool Layer::isVisible()
{
    return visible;
}

bool Layer::tileExists(int x,  int y) const
{
    return x >= 0 && x < getHLength() && y >= 0 && y < getVLength();
}

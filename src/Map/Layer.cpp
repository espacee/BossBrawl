#include "Map/Layer.hpp"

Layer::Layer()
{
    resize(1, 1);
    fill(0);
    x_coord = y_coord = 0;
    depthIndex = 1.f;
    grid = false;

    setGridColor(sf::Color(0, 0, 0));
}

void Layer::resize(unsigned int new_hLength, unsigned int new_vLength)
{
    if (new_hLength >= 1 && new_vLength >= 1)
    {

        hLength = new_hLength;
        vLength = new_vLength;

        map.resize(new_hLength);

        for (unsigned int i = 0; i < new_hLength; i++)
        {
            map[i].resize(new_vLength, 0);
        }

        width = hLength * GRID_SIZE;
        height = vLength * GRID_SIZE;

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
    for (unsigned int i = 0; i < hLength; i++)
    {
        for (unsigned int j = 0; j < vLength; j++)
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

unsigned int Layer::getHLength() const
{
    return hLength;
}

unsigned int Layer::getVLength() const
{
    return vLength;
}

unsigned int Layer::getWidth() const
{
    return width;
}

unsigned int Layer::getHeight() const
{
    return height;
}

bool Layer::gridEnabled()
{
    return grid;
}

void Layer::setGridEnabled(bool yesno)
{
    grid = yesno;
}


void Layer::setGridColor(sf::Color new_gridColor)
{
    gridColor = sf::Color(new_gridColor.r, new_gridColor.g, new_gridColor.b, new_gridColor.a / 2);
}

sf::Color Layer::getGridColor() const
{
    return gridColor;
}

bool Layer::tileExists(unsigned int x, unsigned int y) const
{
    return x < hLength && y < vLength;
}

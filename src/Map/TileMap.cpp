#include "Map/TileMap.hpp"

#include "Core/graphics.hpp"

TileMap::TileMap()
{
    loadTiles();
    nb_layers = 0;
    addLayer();
}

void TileMap::loadTiles()
{
    sprites.push_back(sf::Sprite());

    if (tileSet.loadFromFile("res/img/tileset.png"))
    {
        int ts_width = tileSet.getSize().x;
        int ts_height = tileSet.getSize().y;

        for (int j = 0; j < ts_height; j += GRID_SIZE)
        {
            for (int i = 0; i < ts_width; i += GRID_SIZE)
            {
                sprites.push_back(sf::Sprite(tileSet, sf::IntRect(i, j, GRID_SIZE, GRID_SIZE)));
            }
        }
    }
}

void TileMap::resizeLayer(unsigned int layer, unsigned int new_hLength, unsigned int new_vLength)
{
    if (layerExists(layer))
        layers[layer].resize(new_hLength, new_vLength);
}
void TileMap::setTile(unsigned int layer, unsigned int x, unsigned int y, unsigned int id)
{
    if (layerExists(layer)  && spriteExists(id))
        layers[layer].setTile(x, y, id);
}
unsigned int TileMap::getTile(unsigned int layer, unsigned int x, unsigned int y) const
{
    if (layerExists(layer))
        return layers[layer].getTile(x, y);
    else
        return 0;
}

void TileMap::fillLayer(unsigned int layer, unsigned int id)
{
    if (layerExists(layer) && spriteExists(id))
    {
        layers[layer].fill(id);
    }
}

void TileMap::moveLayer(int x_offset, int y_offset, unsigned int layer)
{
    if (layerExists(layer))
    {
        layers[layer].move(x_offset, y_offset);
    }
}
void TileMap::setLayerPosition(int new_x_coord, int new_y_coord, unsigned int layer)
{
    if (layerExists(layer))
    {
        layers[layer].setPosition(new_x_coord, new_y_coord);
    }
}
void TileMap::addLayer()
{
    nb_layers++;
    layers.push_back(Layer());
}

void TileMap::popLayer()
{
    if (nb_layers > 1)
    {
        layers.pop_back();
        nb_layers--;
    }
}
int TileMap::getLayerSize()
{

    return layers.size();



}
bool TileMap::tileExists(unsigned int x, unsigned int y, unsigned int layer) const
{
    if (layerExists(layer))
        return layers[layer].tileExists(x, y);
    else
        return false;
}
bool TileMap::spriteExists(unsigned int id) const
{
    return id < sprites.size();
}

bool TileMap::layerExists(unsigned int layer) const
{
    return layer < layers.size();
}
void TileMap::display()
{
    for (unsigned int k = 0; k < nb_layers; k++)
    {
        for (unsigned int i = 0; i < layers[k].getHLength(); i++)
        {
            for (unsigned int j = 0; j < layers[k].getVLength(); j++)
            {
                unsigned int id = layers[k].getTile(i, j);

                if (id)
                {
                    sprites[id].setPosition(layers[k].getX() + (int)(i * GRID_SIZE),
                                            layers[k].getY() + (int)(j * GRID_SIZE));
                    graphics::window.draw(sprites[id]);
                }
            }
        }
    }
}

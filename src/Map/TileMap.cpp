#include "Map/TileMap.hpp"

#include "Core/graphics.hpp"


TileMap::TileMap()
{
    loadTiles();
    nb_layers = 0;
    addLayer();

    tilesdrawncons = false;
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

void TileMap::moveLayer(unsigned int layer, int x_offset, int y_offset)
{
    if (layerExists(layer))
    {
        layers[layer].move(x_offset, y_offset);
    }
}
void TileMap::setLayerPosition(unsigned int layer, int new_x_coord, int new_y_coord)
{
    if (layerExists(layer))
    {
        layers[layer].setPosition(new_x_coord, new_y_coord);
    }
}

void TileMap::setLayerDepthIndex(unsigned int layer, float new_depthIndex)
{
    if (layerExists(layer))
    {
        layers[layer].setDepthIndex(new_depthIndex);
    }
}

void TileMap::setLayerGridColor(unsigned int layer, sf::Color gridColor)
{
    if (layerExists(layer))
    {
        layers[layer].setGridColor(gridColor);
    }
}

void TileMap::setLayerGridEnabled(unsigned int layer, bool yesno)
{
    if (layerExists(layer))
    {
        layers[layer].setGridEnabled(yesno);
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
void TileMap::tilesdrawn()
{
    tilesdrawncons = !tilesdrawncons;

    if(tilesdrawncons == false)
        std::cout << "Tiles Counter Disabled." << std::endl;
}
void TileMap::display()
{
    drawnTiles = 0;

    sf::View saveCamera = graphics::window.getView();
    sf::View camera = saveCamera;

    for (unsigned int k = 0; k < nb_layers; k++)
    {
        camera.setCenter(saveCamera.getCenter().x * layers[k].getDepthIndex() - layers[k].getPosition().x,
                         saveCamera.getCenter().y * layers[k].getDepthIndex() - layers[k].getPosition().y);

        graphics::window.setView(camera);

        int xmin = (int)(camera.getCenter().x - camera.getSize().x / 2) / GRID_SIZE;
        int ymin = (int)(camera.getCenter().y - camera.getSize().y / 2) / GRID_SIZE;

        int xmax = (int)(camera.getCenter().x + camera.getSize().x / 2) / GRID_SIZE+1;
        int ymax = (int)(camera.getCenter().y + camera.getSize().y / 2) / GRID_SIZE+1;

        if (xmin < 0) xmin = 0;

        if (ymin < 0) ymin = 0;

        if (xmax < 0) xmax = 0;

        if (ymax < 0) ymax = 0;

        if (xmin > static_cast<int>(layers[k].getHLength())) xmin = layers[k].getHLength();

        if (ymin > static_cast<int>(layers[k].getVLength())) ymin = layers[k].getVLength();

        if (xmax > static_cast<int>(layers[k].getHLength())) xmax = layers[k].getHLength();

        if (ymax > static_cast<int>(layers[k].getVLength())) ymax = layers[k].getVLength();

        if(layers[k].gridEnabled())
        {
            sf::RectangleShape layerBackground(sf::Vector2f(layers[k].getWidth(), layers[k].getHeight()));
            layerBackground.setFillColor(layers[k].getGridColor());
            graphics::window.draw(layerBackground);
        }

        for (int i = xmin; i <= xmax; i++)
        {
            for (int j = ymin; j <= ymax; j++)
            {
                unsigned int id = layers[k].getTile(i, j);
                if (id)
                {
                    sprites[id].setPosition((int)(i * GRID_SIZE),
                                            (int)(j * GRID_SIZE));
                    graphics::window.draw(sprites[id]);
                    drawnTiles++;
                }

                if(layers[k].gridEnabled())
                {
                    sf::Vertex hLine[] =
                    {
                        sf::Vertex(sf::Vector2f(xmin*GRID_SIZE, j * GRID_SIZE), layers[k].getGridColor()),
                        sf::Vertex(sf::Vector2f((xmax)*GRID_SIZE, j * GRID_SIZE), layers[k].getGridColor())
                    };
                    graphics::window.draw(hLine, 2, sf::Lines);
                }
            }

            if(layers[k].gridEnabled())
            {
                sf::Vertex vLine[] =
                {
                    sf::Vertex(sf::Vector2f(i * GRID_SIZE, ymin*GRID_SIZE), layers[k].getGridColor()),
                    sf::Vertex(sf::Vector2f(i * GRID_SIZE, (ymax)*GRID_SIZE), layers[k].getGridColor())
                };
                graphics::window.draw(vLine, 2, sf::Lines);
            }
        }
    }
    if(tilesdrawncons == true)
        std::cout << drawnTiles << std::endl << std::endl;

    graphics::window.setView(saveCamera);
}

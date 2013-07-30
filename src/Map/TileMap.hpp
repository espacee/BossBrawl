#ifndef MAP_TILEMAP_HPP
#define MAP_TILEMAP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Map/Layer.hpp"

/**
 * @brief A tile-based layered map
 *
 * The tile data is stored as a multi dimensional vector of tile ids in each layer.
 * The special id '0' stands for 'air', a.k.a 'empty' tile.
 */
class TileMap
{
public:
    TileMap();

    void loadTiles();

    void resizeLayer(unsigned int layer, unsigned int new_hLength, unsigned int new_vLength);
    void setTile(unsigned int layer, unsigned int x, unsigned int y, unsigned int id);
    unsigned int getTile(unsigned int layer, unsigned int x, unsigned int y) const;

    /**
     * @brief Fill a layer with a specific tile
     *
     * @param layer The layer to fill
     * @param id The tile to fill the layer with. If it is 0, the function will
     *           fill the layer with empty tiles, i.e. clear the layer.
     */
    void fillLayer(unsigned int layer, unsigned int id);

    void moveLayer(unsigned int layer, int x_offset, int y_offset);
    void setLayerPosition(unsigned int layer, int new_x_coord, int new_y_coord);
    void setLayerDepthIndex(unsigned int layer, float new_depthIndex);

    void addLayer();
    void popLayer();

    int getLayerSize();

    bool tileExists(unsigned int x, unsigned int y, unsigned int layer) const;
    bool spriteExists(unsigned int id) const;
    bool layerExists(unsigned int layer) const;

    void display();

    unsigned int nb_layers;
private:
    std::vector< Layer > layers;



    std::vector< sf::Sprite > sprites;
    sf::Texture tileSet;
};

#endif // MAP_TILEMAP_HPP

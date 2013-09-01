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
    ~TileMap();

    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename);

    void setTile(unsigned int layer, unsigned int x, unsigned int y, unsigned int id);
    unsigned int getTile(unsigned int layer, unsigned int x, unsigned int y) const;

    void addLayer(int pos);
    void removeLayer(int pos);
    void moveLayerBackground(int pos);
    void moveLayerForeground(int pos);

    int size();

    inline Layer& operator[](unsigned int index)
    {
        return *(layers[index]);
    }

    bool tileExists(unsigned int x, unsigned int y, unsigned int layer) const;
    bool spriteExists(unsigned int id) const;
    bool layerExists(unsigned int layer) const;

    void draw(sf::RenderWindow& target, unsigned int drawGridForLayer = -1);

private:
    void loadTileset();

    std::vector<Layer*> layers;
    std::vector<sf::Sprite> sprites;
    sf::Texture tileSet;
};

#endif // MAP_TILEMAP_HPP

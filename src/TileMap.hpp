#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>

typedef unsigned int uint;

/**
 * @brief A tile-based map
 *
 * The tile data is stored as a multi dimensional vector of tile ids.
 * The special id '0' stands for 'air', a.k.a 'empty' tile.
 */
class TileMap
{
public:
    TileMap();

    void LoadTiles();

    void Resize(uint new_hLength, uint new_vLength);
    void SetTile(uint x, uint y, uint id);
    uint GetTile(uint x, uint y) const;

    /**
     * @brief Fill the map with a specific tile
     * @param id The tile to fill the map with. If it is 0, the function will
     *           fill the map with empty tiles, i.e. clear the map.
     */
    void Fill(uint id);

    uint GetHLength() const;
    uint GetVLength() const;
    uint GetWidth() const;
    uint GetHeight() const;

    void Draw(sf::RenderWindow &w);

    bool TileExists(uint x, uint y) const;
    bool SpriteExists(uint id) const;

private:
    static const int GRID_SIZE = 40;
    std::vector< std::vector<uint> > map;
    uint hLength, vLength, width, height;

    std::vector< sf::Sprite > sprites;
    sf::Texture tileSet;

};

#endif // TILEMAP_HPP

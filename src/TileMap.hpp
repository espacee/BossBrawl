#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>

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

    void Resize(unsigned int new_hLength, uint new_vLength);
    void SetTile(unsigned int x, uint y, uint id);
    unsigned int GetTile(uint x, uint y) const;

    /**
     * @brief Fill the map with a specific tile
     * @param id The tile to fill the map with. If it is 0, the function will
     *           fill the map with empty tiles, i.e. clear the map.
     */
    void Fill(unsigned int id);

    unsigned int GetHLength() const;
    unsigned int GetVLength() const;
    unsigned int GetWidth() const;
    unsigned int GetHeight() const;

    void Draw(sf::RenderWindow &w);

    bool TileExists(unsigned int x, uint y) const;
    bool SpriteExists(unsigned int id) const;

private:
    static const int GRID_SIZE = 40;
    std::vector< std::vector<unsigned int> > map;
    unsigned int hLength, vLength, width, height;

    std::vector< sf::Sprite > sprites;
    sf::Texture tileSet;

};

#endif // TILEMAP_HPP

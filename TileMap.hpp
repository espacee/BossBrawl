#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>

#define GRID_SIZE 40

typedef unsigned int uint;

class TileMap
{
public:
    TileMap();

    void LoadTiles();

    void Resize(uint new_hLength, uint new_vLength);
    void SetTile(uint x, uint y, uint id);
    uint GetTile(uint x, uint y);
    void Fill(uint id);

    uint GetHLength();
    uint GetVLength();
    uint GetWidth();
    uint GetHeight();

    void Draw(sf::RenderWindow &w);

    bool TileExist(uint x, uint y);
    bool SpriteExist(uint id);

private:
    std::vector< std::vector<uint> > map;
    uint hLength, vLength, width, height;

    std::vector< sf::Sprite > sprites;
    sf::Texture tileSet;

};

#endif // TILEMAP_HPP

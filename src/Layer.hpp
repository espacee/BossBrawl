#ifndef LAYER_HPP
#define LAYER_HPP

#include <SFML/Graphics.hpp>

const int GRID_SIZE = 40;

class Layer
{
public:
    Layer();
    Layer(unsigned int new_layerID);


    void Resize(unsigned int new_hLength, unsigned int new_vLength);
    void SetTile(unsigned int x, unsigned int y, unsigned int id);
    unsigned int GetTile(unsigned int x, unsigned int y) const;

    /**
     * @brief Fill the map with a specific tile
     * @param id The tile to fill the map with. If it is 0, the function will
     *           fill the map with empty tiles, i.e. clear the map.
     */
    void Fill(unsigned int id);

    void Move(int x_offset, int y_offset);
    void SetPosition(int new_x_coord, int new_y_coord);
    int GetX() const;
    int GetY() const;

    unsigned int GetHLength() const;
    unsigned int GetVLength() const;
    unsigned int GetWidth() const;
    unsigned int GetHeight() const;

    bool TileExists(unsigned int x, unsigned int y) const;

private:
    std::vector< std::vector<unsigned int> > map;
    unsigned int hLength, vLength, width, height;
    unsigned int layerID;

    int x_coord, y_coord;
};

#endif // LAYER_HPP

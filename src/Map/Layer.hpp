#ifndef MAP_LAYER_HPP
#define MAP_LAYER_HPP

#include <SFML/Graphics.hpp>

constexpr int GRID_SIZE = 40;

/**
 * @brief A layer of tiles
 */
class Layer
{
public:
    Layer();
    Layer(unsigned int new_layerID);


    void resize(unsigned int new_hLength, unsigned int new_vLength);
    void setTile(unsigned int x, unsigned int y, unsigned int id);
    unsigned int getTile(unsigned int x, unsigned int y) const;

    /**
     * @brief Fill the layer with a specific tile
     * @param id The tile to fill the layer with. If it is 0, the function will
     *           fill the layer with empty tiles, i.e. clear the layer.
     */
    void fill(unsigned int id);

    void move(int x_offset, int y_offset);
    void setPosition(int new_x_coord, int new_y_coord);
    void setDepthIndex(float new_depthIndex);
    int getX() const;
    int getY() const;

    sf::Vector2f getPosition();
    float getDepthIndex();
    unsigned int getHLength() const;
    unsigned int getVLength() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;

    bool gridEnabled();
    void setGridEnabled(bool yesno);
    void setGridColor(sf::Color new_gridColor);
    sf::Color getGridColor() const;

    void setVisible(bool yesno);
    bool isVisible();

    bool tileExists(unsigned int x, unsigned int y) const;

private:
    std::vector< std::vector<unsigned int> > map;
    unsigned int hLength, vLength, width, height;
    bool grid, visible;
    sf::Color gridColor;

    int x_coord, y_coord;
    float depthIndex;
};

#endif // MAP_LAYER_HPP

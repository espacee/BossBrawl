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
    Layer(const std::string& name);

    void resize(unsigned int new_hLength, unsigned int new_vLength);
    void setTile(unsigned int x, unsigned int y, unsigned int id);
    unsigned int getTile(unsigned int x, unsigned int y) const;

    /**
     * @brief Fill the layer with a specific tile
     * @param id The tile to fill the layer with. If it is 0, the function will
     *           fill the layer with empty tiles, i.e. clear the layer.
     */
    void fill(unsigned int id);

    inline void move(int x_offset, int y_offset)
    {
        m_x += x_offset;
        m_y += y_offset;
    }

    inline void setPosition(int new_x_coord, int new_y_coord)
    {
        m_x = new_x_coord;
        m_y = new_y_coord;
    }

    inline void setDepthIndex(float new_depthIndex)
    {
        m_depthIndex = new_depthIndex;
    }

    inline int getX() const
    {
        return m_x;
    }

    inline int getY() const
    {
        return m_y;
    }

    inline sf::Vector2f getPosition() const
    {
        return sf::Vector2f(m_x, m_y);
    }

    inline float getDepthIndex() const
    {
        return m_depthIndex;
    }

    inline int getHLength() const
    {
        return m_tiles.size();
    }

    inline int getVLength() const
    {
        return (m_tiles.size() ? m_tiles[0].size() : 0);
    }

    inline int getWidth() const
    {
        return getHLength() * GRID_SIZE;
    }

    inline int getHeight() const
    {
        return getVLength() * GRID_SIZE;
    }

    inline void setName(const std::string& name)
    {
        m_name = name;
    }

    inline const std::string& getName() const
    {
        return m_name;
    }

    inline void setGridColor(sf::Color new_gridColor)
    {
        m_gridColor = new_gridColor;
    }

    inline sf::Color getGridColor() const
    {
        return m_gridColor;
    }

    inline void setVisible(bool yesno)
    {
        m_visible = yesno;
    }

    inline bool isVisible() const
    {
        return m_visible;
    }

    inline bool tileExists(int x,  int y) const
    {
        return x >= 0 && x < getHLength() && y >= 0 && y < getVLength();
    }

private:
    std::vector< std::vector<unsigned int> > m_tiles;
    bool m_visible;
    sf::Color m_gridColor;
    std::string m_name;

    int m_x, m_y;
    float m_depthIndex;

    friend class TileMap;
};

#endif // MAP_LAYER_HPP

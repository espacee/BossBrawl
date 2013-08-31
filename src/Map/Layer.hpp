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

    void resize(unsigned int w, unsigned int h);
    void setTile(unsigned int x, unsigned int y, unsigned int id);
    unsigned int getTile(unsigned int x, unsigned int y) const;

    /**
     * @brief Fill the layer with a specific tile
     * @param id The tile to fill the layer with. If it is 0, the function will
     *           fill the layer with empty tiles, i.e. clear the layer.
     */
    void fill(unsigned int id);

    inline void move(int xoff, int yoff)
    {
        m_x += xoff;
        m_y += yoff;
    }

    inline void setPosition(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

    inline void setDepthIndex(float index)
    {
        m_depthIndex = index;
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

    inline void setGridColor(sf::Color color)
    {
        m_gridColor = color;
    }

    inline sf::Color getGridColor() const
    {
        return m_gridColor;
    }

    inline void setVisible(bool visible)
    {
        m_visible = visible;
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
    std::string m_name;
    bool m_visible;
    sf::Color m_gridColor;
    int m_x, m_y;
    float m_depthIndex;

    std::vector< std::vector<unsigned int> > m_tiles;

    friend class TileMap;
};

#endif // MAP_LAYER_HPP

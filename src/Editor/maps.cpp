#include "maps.hpp"
#include <vector>

namespace maps {

std::vector<TileMap*> m_tilemaps;
unsigned m_active = 0;

bool loadFromFile(QString filename)
{
    TileMap *map = new TileMap;
    if (map->loadFromFile(filename.toStdString())) {
        m_tilemaps.push_back(map);
        return true;
    }
    delete map;
    return false;
}

TileMap& current()
{
#ifdef BRAWL_DEBUG
    assert(m_active < m_tilemaps.size());
#endif
    return *(m_tilemaps[m_active]);
}

void cleanup()
{
    for (auto m : m_tilemaps)
        delete m;
}

void addNew()
{
    TileMap *map = new TileMap;
    map->addLayer(0);
    m_tilemaps.push_back(map);
}

int size()
{
    return m_tilemaps.size();
}

void setActive(int index)
{
    m_active = index;
}



}

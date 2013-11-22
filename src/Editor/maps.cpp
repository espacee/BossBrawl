#include "maps.hpp"
#include <vector>

namespace maps {

std::vector<TileMap *> m_tilemaps;
std::vector<EntityContainer *> m_entityContainers;
unsigned m_active = 0;

bool loadFromFile(QString filename)
{
    TileMap *map = new TileMap;

    if (map->loadFromFile(filename.toStdString())) {
        m_tilemaps.push_back(map);
        EntityContainer *cont = new EntityContainer;
        m_entityContainers.push_back(cont);
        return true;
    }

    delete map;
    return false;
}

TileMap &current()
{
#ifdef BRAWL_DEBUG
    assert(m_active < m_tilemaps.size());
#endif
    return *(m_tilemaps[m_active]);
}

EntityContainer &currentEntityContainer()
{
#ifdef BRAWL_DEBUG
    assert(m_active < m_entityContainers.size());
#endif
    return *(m_entityContainers[m_active]);
}

void cleanup()
{
    for (auto m : m_tilemaps)
        delete m;

    for (auto c : m_entityContainers)
        delete c;
}

void addNew()
{
    TileMap *map = new TileMap;
    EntityContainer *cont = new EntityContainer;
    map->addLayer(0);
    m_tilemaps.push_back(map);
    m_entityContainers.push_back(cont);
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

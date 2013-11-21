#include "maps.hpp"
#include <vector>

namespace maps {

std::vector<TileMap> m_tilemaps;
int m_active = 0;

TileMap& current()
{
    static bool inited;
    if (!inited) {
        m_tilemaps.emplace_back();
        inited = true;
    }
    return m_tilemaps[m_active];
}

}

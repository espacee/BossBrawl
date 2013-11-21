#include "maps.hpp"

namespace maps {

TileMap& current()
{
    static TileMap map;
    return map;
}

}

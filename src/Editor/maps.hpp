#ifndef MAPS_HPP
#define MAPS_HPP

#include <Map/TileMap.hpp>
#include <QString>

namespace maps {

bool loadFromFile(QString filename);
TileMap& current();
void cleanup();

}

#endif // MAPS_HPP

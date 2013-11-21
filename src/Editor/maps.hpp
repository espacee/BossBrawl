#ifndef MAPS_HPP
#define MAPS_HPP

#include <Map/TileMap.hpp>
#include <QString>

namespace maps {

bool loadFromFile(QString filename);
void addNew();
TileMap& current();
void cleanup();
int size();
void setActive(int index);

}

#endif // MAPS_HPP

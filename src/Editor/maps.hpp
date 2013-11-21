#ifndef MAPS_HPP
#define MAPS_HPP

#include <Map/TileMap.hpp>
#include <Entities/EntityContainer.hpp>
#include <QString>

namespace maps {

bool loadFromFile(QString filename);
void addNew();
TileMap& current();
EntityContainer& currentEntityContainer();
void cleanup();
int size();
void setActive(int index);

}

#endif // MAPS_HPP

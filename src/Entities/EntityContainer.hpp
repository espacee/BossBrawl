#ifndef ENTITIES_ENTITYCONTAINER_HPP
#define ENTITIES_ENTITYCONTAINER_HPP

#include <SFML/Graphics.hpp>
#include "Util/math.hpp"
#include "Map/TileMap.hpp"
#include "Entities/Enemy.hpp"
#include "Entities/Entity.hpp"
#include "Entities/DefaultEnemy.hpp"
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include <fstream>


/**
 * @brief The Entity Container Class
 */
class EntityContainer
{
public:
    EntityContainer();

    void onInit();

    void updateEntities(Layer &mainLayer);
    void displayEntities(sf::RenderWindow &window);

    void addEntity(std::string entity, float posX, float posY, bool editorMode);
    void deleteEntity(float posX, float posY);

    bool loadFromFile(const std::string& filename, bool editorMode);
    bool saveToFile(const std::string& filename);

    void reset();




private:
    TileMap* map;
    std::vector<DefaultEnemy*> defaultEnemy;
};

#endif // ENTITIES_ENTITYCONTAINER_HPP

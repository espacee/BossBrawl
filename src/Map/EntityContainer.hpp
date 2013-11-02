#ifndef GAME_ENTITYCONTAINER_HPP
#define GAME_ENTITYCONTAINER_HPP

#include <SFML/Graphics.hpp>
#include "Util/math.hpp"
#include "Map/TileMap.hpp"
#include "Entities/Enemy.hpp"
#include "Entities/Entity.hpp"
#include "Entities/DefaultEnemy.hpp"
#include <iostream>
#include <vector>


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

    void addEntity(std::string entity, float posX, float posY);




private:
    TileMap* map;
    std::vector<DefaultEnemy*> defaultEnemy;
};

#endif // GAME_ENTITYCONTAINER_HPP

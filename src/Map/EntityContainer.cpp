#include "Map/EntityContainer.hpp"


EntityContainer::EntityContainer()
{
    onInit();

}
void EntityContainer::onInit()
{
   defaultEnemy.push_back(new DefaultEnemy(200,300));


}
void EntityContainer::updateEntities(Layer &mainLayer)
{
    for(unsigned int i = 0; i < defaultEnemy.size(); i++ )
        defaultEnemy[i]->update(mainLayer);


}
void EntityContainer::displayEntities(sf::RenderWindow &window)
{
    for(unsigned int i = 0; i < defaultEnemy.size(); i++)
        defaultEnemy[i]->display(window);


}

void EntityContainer::addEntity(std::string entity, float posX, float posY)
{
    if(entity == "defaultEnemy")
    {
        defaultEnemy.push_back(new DefaultEnemy(posX, posY));
    }


    }


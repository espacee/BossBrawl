#include "Entities/EntityContainer.hpp"
#include "SFML/Graphics.hpp"


EntityContainer::EntityContainer()
{
    onInit();

}
void EntityContainer::onInit()
{


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

void EntityContainer::addEntity(std::string entity, float posX, float posY, bool editorMode)
{
    if(entity == "defaultEnemy")
    {
        defaultEnemy.push_back(new DefaultEnemy( posX, posY, editorMode));
    }
}
void EntityContainer::deleteEntity(float posX, float posY)
{
    for(unsigned int i = 0; i < defaultEnemy.size(); i++)
    {
        if(defaultEnemy[i]->contains(posX, posY))
              defaultEnemy.erase(defaultEnemy.begin() + i);
    }
}


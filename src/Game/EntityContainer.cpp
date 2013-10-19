#include "Game/EntityContainer.hpp"


EntityContainer::EntityContainer()
{
    onInit();

}
void EntityContainer::onInit()
{
   defaultEnemy.push_back(new DefaultEnemy());


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

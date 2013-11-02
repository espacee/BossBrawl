#include "Entities/EntityContainer.hpp"


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
bool EntityContainer::saveToFile(const std::string &filename)
{
    std::ofstream file(filename);

    if(!file)
        return false;

    //name and quantity of the entity
    file << "defaultEnemy" <<'\n';
    file << defaultEnemy.size() << '\n';


    for(unsigned int i = 0; i < defaultEnemy.size(); i++)
    {
        file << defaultEnemy[i]->getPosition().x <<' '<< defaultEnemy[i]->getPosition().y << '\n';
    }

    return true;
}
bool EntityContainer::loadFromFile(const std::string &filename, bool editorMode)
{
    std::ifstream file(filename);

    if (!file)
        return false;

    std::string entityname;
    file.get(); // Discard newline character
    std::getline(file, entityname);
    int vectorsize;
    file >> vectorsize;



    for(int i = 0; i < vectorsize; ++i)
    {
        int x, y;
        file >> x >> y;
        defaultEnemy.push_back(new DefaultEnemy(x,y,editorMode));
    }

    if (!file) {
        return false;
    }

return true;


}
void EntityContainer::reset()
{
    for(auto l : defaultEnemy)
        delete l;

    defaultEnemy.clear();
}




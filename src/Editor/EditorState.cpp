#include "Editor/EditorState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Util/view.hpp"

EditorState::EditorState()
{
    map.resizeLayer(0,10,10);
    map.setLayerGridColor(0,sf::Color(0,0,0,127));
    map.setLayerGridEnabled(0,true);

    map.setTile(0,1,1,1); map.setTile(0,2,1,2); map.setTile(0,3,1,3); map.setTile(0,4,1,4); map.setTile(0,5,1,5);


    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));
    testTargetTexture.loadFromFile("res/img/target.png");
    testTargetTexture.setSmooth(true);
    testTarget.setTexture(testTargetTexture);
    testTarget.setOrigin(15, 15);

}

void EditorState::onSet()
{
    std::cout << "Press T if you want to enable the Tiles Counter" << std::endl;

    graphics::window.setTitle("editor");
    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));
    testTarget.setPosition(200,200);



    currentTile = 1;


}
void EditorState::onUpdate()
{
    using graphics::window;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        testTarget.move(0, -10);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        testTarget.move(10, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        testTarget.move(0, 10);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        testTarget.move(-10, 0);



    testTarget.rotate(5);
    moveViewTowardsPoint(camera, testTarget.getPosition().x, testTarget.getPosition().y, 0.05f);

    window.clear(sf::Color(225, 219, 219));

    graphics::window.setView(camera);
    map.display();
    window.draw(testTarget);

    graphics::window.setView(sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y)));

}
void EditorState::onEvent(const sf::Event &event)
{
    if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)/* &&  layertest.isMoreOptionsActive() == false */)
        stateDriver::setState("menu");
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
        map.tilesdrawn();
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        buttonPressed = true;
    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        buttonPressed = false;


    if(buttonPressed == true){
        tileSelector();
        if(event.type == sf::Event::MouseMoved && event.MouseMoved )
            tileSelector();
    }
}
void EditorState::tileSelector()
{
    if(currentTool == 1)
        penTool();

    if(currentTool ==2)
        eraserTool();

    if(currentTool == 3)
        fillTool();

    if(currentTool == 4)
        handTool();
}
void EditorState::penTool()
{
     cx = camera.getCenter().x;
     cy = camera.getCenter().y;
     tx = (sf::Mouse::getPosition(graphics::window).x + (cx - (graphics::window.getSize().x /2))) / GRID_SIZE;
     ty = (sf::Mouse::getPosition(graphics::window).y + (cy - (graphics::window.getSize().y /2))) / GRID_SIZE;

     map.setTile(0, tx, ty, currentTile);
}
void EditorState::eraserTool()
{
    cx = camera.getCenter().x;
    cy = camera.getCenter().y;
    tx = (sf::Mouse::getPosition(graphics::window).x + (cx - (graphics::window.getSize().x /2))) / GRID_SIZE;
    ty = (sf::Mouse::getPosition(graphics::window).y + (cy - (graphics::window.getSize().y /2))) / GRID_SIZE;

    map.setTile(0, tx, ty, 0);
}
void EditorState::fillTool()
{
    cx = camera.getCenter().x;
    cy = camera.getCenter().y;
    tx = (sf::Mouse::getPosition(graphics::window).x + (cx - (graphics::window.getSize().x /2))) / GRID_SIZE;
    ty = (sf::Mouse::getPosition(graphics::window).y + (cy - (graphics::window.getSize().y /2))) / GRID_SIZE;

    if(map.tileExists(tx, ty, 0))
         map.fillLayer(0, currentTile);
}
void EditorState::handTool()
{



}

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

   /**
    map.addLayer();
    map.resizeLayer(1,100,100);
    map.setLayerGridEnabled(1, true);  **/



    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));
    testTargetTexture.loadFromFile("res/img/target.png");
    testTargetTexture.setSmooth(true);
    testTarget.setTexture(testTargetTexture);
    testTarget.setOrigin(15, 15);
}

void EditorState::onSet()
{
    graphics::window.setTitle("editor");
    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));
    currentTool = 1;

    topPanel.setSize(graphics::window.getSize().x, 32);
    topPanel.setPosition(0, 0);
    topPanel.setBackgroundColor(sf::Color(40, 40, 40));

    penButton.setIcon("res/img/GUI/pen.png");
    penButton.setPosition(1, 1);
    penButton.setToggleable(true);

    eraserButton.setIcon("res/img/GUI/eraser.png");
    eraserButton.setPosition(36, 1);
    eraserButton.setToggleable(true);

    fillButton.setIcon("res/img/GUI/fill.png");
    fillButton.setPosition(71, 1);
    fillButton.setToggleable(true);

    handButton.setIcon("res/img/GUI/hand.png");
    handButton.setPosition(106, 1);
    handButton.setToggleable(true);

    rightPanel.setSize(200, graphics::window.getSize().y);
    rightPanel.setPosition(graphics::window.getSize().x - rightPanel.getWidth(), 0);
    rightPanel.setBackgroundColor(sf::Color(70, 70, 70));

    tileSetButton.setText("TileSet >>");
    tileSetButton.setGeometry(rightPanel.getX() + 2, topPanel.getY() + topPanel.getHeight() + 2, rightPanel.getWidth() - 4, 50);
    tileSetButton.setGeometry(rightPanel.getX() + 2, topPanel.getY() + topPanel.getHeight() + 2, rightPanel.getWidth() - 4, 50);

    layerList.setGeometry(rightPanel.getX(), tileSetButton.getY() + tileSetButton.getHeight() + 2, rightPanel.getWidth(), 100);
    layerList.setHeight(rightPanel.getHeight() - layerList.getY());
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

    if (penButton.isReleased()) {
        currentTool = 1;
        std::cout << "current tool is " << getTool() << std::endl;
        eraserButton.untoggle();
        fillButton.untoggle();
        handButton.untoggle();
    }

    if (eraserButton.isReleased()) {
        currentTool = 2;
        std::cout << "current tool is " << getTool() << std::endl;
        penButton.untoggle();
        fillButton.untoggle();
        handButton.untoggle();
    }

    if (fillButton.isReleased()) {
        currentTool = 3;
        std::cout << "current tool is " << getTool() << std::endl;
        penButton.untoggle();
        eraserButton.untoggle();
        handButton.untoggle();
    }

    if (handButton.isReleased()) {
        currentTool = 4;
        std::cout << "current tool is " << getTool() << std::endl;
        penButton.untoggle();
        eraserButton.untoggle();
        fillButton.untoggle();
    }

    testTarget.rotate(5);
    moveViewTowardsPoint(camera, testTarget.getPosition().x, testTarget.getPosition().y, 0.05f);

//_________________________________________________________________________________________________________________________________
    window.clear(sf::Color(200, 200, 200));




    graphics::window.setView(camera);
    map.display();
    window.draw(testTarget);

    graphics::window.setView(sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y)));
    rightPanel.display(graphics::window);
    tileSetButton.display(graphics::window);

    topPanel.display(graphics::window);
    penButton.display(graphics::window);
    eraserButton.display(graphics::window);
    fillButton.display(graphics::window);
    handButton.display(graphics::window);

    layerList.display(graphics::window);

}
void EditorState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M)
        consoleCommands();
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
        if(currentTool == 1)
            penEnabled();
        else if(currentTool == 2)
                eraserEnabled();

    }


    rightPanel.processEvents(event);
    topPanel.processEvents(event);
    penButton.processEvents(event);
    eraserButton.processEvents(event);
    fillButton.processEvents(event);
    handButton.processEvents(event);
    tileSetButton.processEvents(event);

    layerList.processEvents(event);
}
int EditorState::getTool()
{
    return currentTool;

}
void EditorState::consoleCommands()
{
    int option;
    std::cout << "Choose an Option from the menu.\n1. Add Layer\n2. Delete Layer\n3. Check current Layer" << std::endl;
    std::cin >> option;

    if (option == 1) {
        int length, width;

        map.addLayer();
        std::cout << "Layer " << (map.getLayerSize() - 1) << " Added." << std::endl;
        std::cout << "To what do you want to resize it?" << std::endl;
        std::cin >> length;
        std::cin >> width;
        map.resizeLayer((map.getLayerSize() - 1), length, width);
        std::cout << "Layer resized to " << length << " By " << width << std::endl;
    }

    if (option == 2) {
        std::cout << "Layer " << (map.getLayerSize() - 1) << " Added." << std::endl;
        map.popLayer();
    }

    if (option == 3) {

        system("CLS");
        std::cout << "the current Layer is " << (map.getLayerSize() - 1) << "." << std::endl;
        std::cout << "what do you want to do next?\n1. Resize Layer\n2.Fill Layer\n3.Set LayerGrid Enabled or Disabled." << std::endl;
        std::cin >> option;

        if (option == 1) {
            int length, width;
            std::cout << "the next 2 numbers needs to be the Tile Length & Tile width" << std::endl;
            std::cin >> length;
            std::cin >> width;
            map.resizeLayer((map.getLayerSize() - 1), length, width);
            std::cout << "Layer resized to " << length << " By " << width << std::endl;

        }
        else if (option == 2)
        {
            int tileid;
            std::cout << "what tile Id?" << std::endl;
            std::cin >> tileid;
            map.fillLayer((map.getLayerSize() - 1), tileid);
            std::cout << "Layer filled." << std::endl;
        }
        else if(option == 3)
        {
          int yesno, layer;

          std::cout << "What Layer?" << std::endl;
          std::cin >> layer;
          std::cout << "Do you want to enable or disable it?\n1. Yes\n2. No" << std::endl;
          std::cin >> yesno;

          if(yesno == 1)
              map.setLayerGridEnabled(layer, true);
          else if(yesno == 2)
              map.setLayerGridEnabled(layer, false);
        }
    }
}
void EditorState::penEnabled(){

       cx = camera.getCenter().x;
       cy = camera.getCenter().y;

       tx = (sf::Mouse::getPosition(graphics::window).x + (cx - ((graphics::window.getSize().x) / 2))) / GRID_SIZE;
       ty = (sf::Mouse::getPosition(graphics::window).y + (cy - ((graphics::window.getSize().y) /2))) / GRID_SIZE;

           map.setTile(0, tx, ty, 1);
       }
void EditorState::eraserEnabled()
{
    cx = camera.getCenter().x;
    cy = camera.getCenter().y;

    tx = (sf::Mouse::getPosition(graphics::window).x + (cx - ((graphics::window.getSize().x) / 2))) / GRID_SIZE;
    ty = (sf::Mouse::getPosition(graphics::window).y + (cy - ((graphics::window.getSize().y) /2))) / GRID_SIZE;

        map.setTile(0, tx, ty, 0);
}
void EditorState::fillEnabled()
{


}
void EditorState::handEnabled()
{


}




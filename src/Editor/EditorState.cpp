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

    penButton.setToggleable(true);
    eraserButton.setToggleable(true);
    fillButton.setToggleable(true);
    handButton.setToggleable(true);


}

void EditorState::onSet()
{
    std::cout << "Press T if you want to enable the Tiles Counter" << std::endl;

    graphics::window.setTitle("editor");
    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));
    testTarget.setPosition(200,200);

    topPanel.setPosition(4,40);
    topPanel.setSize(sf::Vector2f(graphics::window.getSize().x-8, 30));
    topPanel.setFillColor(sf::Color(64,59,59));

    leftPanel.setPosition(4,70);
    leftPanel.setSize(sf::Vector2f(36,graphics::window.getSize().y-70-4));
    leftPanel.setFillColor(sf::Color(45,40,40));

    botBar.setPosition(leftPanel.getPosition().x+leftPanel.getSize().x,
                       leftPanel.getPosition().y+leftPanel.getSize().y-20);
    botBar.setSize(sf::Vector2f(graphics::window.getSize().x-botBar.getPosition().x-4,
                                20));
    botBar.setFillColor(sf::Color(35,30,30));

    rightPanel.setPosition(graphics::window.getSize().x-200-4,70);
    rightPanel.setSize(sf::Vector2f(200,graphics::window.getSize().y-rightPanel.getPosition().y-24));
    rightPanel.setFillColor(sf::Color(45,40,40));

    backgroundTop.setPosition(0,0);
    backgroundTop.setSize(sf::Vector2f(graphics::window.getSize().x, topPanel.getPosition().y));
    backgroundTop.setFillColor(sf::Color(85,79,79));

    backgroundRight.setPosition(topPanel.getPosition().x+topPanel.getSize().x, 0);
    backgroundRight.setSize(sf::Vector2f(4,graphics::window.getSize().y));
    backgroundRight.setFillColor(sf::Color(85,79,79));

    backgroundBot.setPosition(0,graphics::window.getSize().y-4);
    backgroundBot.setSize(sf::Vector2f(graphics::window.getSize().x,4));
    backgroundBot.setFillColor(sf::Color(85,79,79));

    backgroundLeft.setPosition(0,0);
    backgroundLeft.setSize(sf::Vector2f(4,graphics::window.getSize().y));
    backgroundLeft.setFillColor(sf::Color(85,79,79));

    backButton.setIcon("res/img/GUI/back.png");
    backButton.resetGeometry();
    backButton.setPosition(graphics::window.getSize().x-backButton.getWidth()-4,4);
    backButton.setColorScheme(sf::Color(85,79,79), sf::Color(0, 170, 240), sf::Color(0, 80, 170));

    iconTexture.loadFromFile("res/img/GUI/icon.png");
    icon.setTexture(iconTexture);

    newButton.setText("New");
    openButton.setText("Open");
    saveButton.setText("Save");
    penButton.setIcon("res/img/GUI/pen.png");
    eraserButton.setIcon("res/img/GUI/eraser.png");
    fillButton.setIcon("res/img/GUI/fill.png");
    handButton.setIcon("res/img/GUI/hand.png");


    newButton.setSize(140,30);
    openButton.setSize(newButton.getWidth(), newButton.getHeight());
    saveButton.setSize(newButton.getWidth(), newButton.getHeight());


    newButton.setPosition(40,5);
    openButton.setPosition(newButton.getX()+newButton.getWidth()+10,newButton.getY());
    saveButton.setPosition(openButton.getX()+openButton.getWidth()+10, openButton.getY());

    penButton.setPosition((leftPanel.getPosition().x + 3),(leftPanel.getPosition().y  + 5));
    eraserButton.setPosition((leftPanel.getPosition().x + 3),(penButton.getY() + eraserButton.getWidth() + 5));
    fillButton.setPosition((leftPanel.getPosition().x + 3),(eraserButton.getY() + fillButton.getWidth() + 5));
    handButton.setPosition((leftPanel.getPosition().x + 3),(fillButton.getY() + handButton.getWidth() + 5));
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


    if(backButton.isReleased())
        stateDriver::setState("menu");

    //_______ Tool Selection ___________  //
    if(penButton.isReleased()){
        currentTool = 1;
        penButton.isToggled();
        eraserButton.untoggle();
        fillButton.untoggle();
        handButton.untoggle();
        std::cout << "Current Tool: " << currentTool << std::endl;
    }
    if(eraserButton.isReleased()){
        currentTool = 2;
        eraserButton.isToggled();
        penButton.untoggle();
        fillButton.untoggle();
        handButton.untoggle();
        std::cout << "Current Tool: " << currentTool << std::endl;
    }
    if(fillButton.isReleased()){
        currentTool = 3;
        fillButton.isToggled();
        eraserButton.untoggle();
        penButton.untoggle();
        handButton.untoggle();
        std::cout << "Current Tool: " << currentTool << std::endl;
    }
    if(handButton.isReleased()){
        currentTool = 4;
        handButton.isToggled();
        eraserButton.untoggle();
        fillButton.untoggle();
        penButton.untoggle();
        std::cout << "Current Tool: " << currentTool << std::endl;
    }
    // ______ Tool Selection End __________ //

    testTarget.rotate(5);
    moveViewTowardsPoint(camera, testTarget.getPosition().x, testTarget.getPosition().y, 0.05f);

    window.clear(sf::Color(225, 219, 219));

    graphics::window.setView(camera);
    map.display();
    window.draw(testTarget);

    graphics::window.setView(sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y)));

    window.draw(topPanel);
    window.draw(leftPanel);
    window.draw(botBar);
    window.draw(rightPanel);
    window.draw(backgroundTop);
    window.draw(backgroundRight);
    window.draw(backgroundBot);
    window.draw(backgroundLeft);
    backButton.display(window);
    window.draw(icon);
    newButton.display(window);
    openButton.display(window);
    saveButton.display(window);
    penButton.display(window);
    eraserButton.display(window);
    fillButton.display(window);
    handButton.display(window);
}
void EditorState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T)
        map.tilesdrawn();


    backButton.processEvents(event);
    newButton.processEvents(event);
    openButton.processEvents(event);
    saveButton.processEvents(event);
    penButton.processEvents(event);
    eraserButton.processEvents(event);
    fillButton.processEvents(event);
    handButton.processEvents(event);
}

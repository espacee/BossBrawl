#include "Editor/EditorState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Util/view.hpp"

EditorState::EditorState()
{

    map.fillLayer(0, 1);
    camera = sf::View(sf::FloatRect(0,0,graphics::window.getSize().x, graphics::window.getSize().y));
    testTargetTexture.loadFromFile("res/img/target.png");
    testTargetTexture.setSmooth(true);
    testTarget.setTexture(testTargetTexture);
    testTarget.setOrigin(15, 15);

}

void EditorState::onSet()
{
    graphics::window.setTitle("editor");
    camera = sf::View(sf::FloatRect(0,0,graphics::window.getSize().x, graphics::window.getSize().y));
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

    test.setGeometry(rightPanel.getX(), topPanel.getY() + topPanel.getHeight() + 55, 20, 200);

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

    if(penButton.isReleased())
        currentTool = 1;
    if(eraserButton.isReleased())
        currentTool = 2;
    if(fillButton.isReleased())
        currentTool = 3;
    if(handButton.isReleased())
        currentTool = 4;


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

    test.display(graphics::window);
}
void EditorState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");

    rightPanel.processEvents(event);
    topPanel.processEvents(event);
    penButton.processEvents(event);
    eraserButton.processEvents(event);
    fillButton.processEvents(event);
    handButton.processEvents(event);
    tileSetButton.processEvents(event);

    test.processEvents(event);
}

int EditorState::getTool()
{
    return currentTool;

}

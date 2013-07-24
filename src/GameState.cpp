#include "GameState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"


GameState::GameState()
{



    fpsText.setFont(graphics::font);
    map.fillLayer(0,1);

    fpsText.setCharacterSize(16);
    fpsText.setPosition(5,graphics::window.getSize().y-20);

    testTargetTexture.loadFromFile("res/img/target.png");
    testTargetTexture.setSmooth(true);
    testTarget.setTexture(testTargetTexture);
    testTarget.setOrigin(15,15);

}
void GameState::onSet()
{

    graphics::window.setTitle("game");

    editorHUD.init();
    editorHUD.setEnabled(false);

    camera.setSmooth(20);

}
void GameState::onUpdate()
{
    using graphics::window;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        testTarget.move(0,-10);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        testTarget.move(10,0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        testTarget.move(0,10);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        testTarget.move(-10,0);




    /** Counts Layer Size **/
   std::string layers = "Layer(s): " + std::to_string(map.getLayerSize());
    editorHUD.layerText.setString(layers);

    testTarget.rotate(5);
    camera.setTarget(testTarget.getPosition());

    camera.update();

    window.clear(sf::Color(0,0,0));

   editorHUD.layerButtons();

    camera.cameraMode();
    map.display();
    window.draw(testTarget);

    camera.hudMode();

    if(editorHUD.getEnabled()){
        editorHUD.display();
        graphics::window.draw(editorHUD.layerText);
    }

    fpsText.setString("Fps: " + std::to_string(stateDriver::getFps()));
    window.draw(fpsText);
}

void GameState::onEvent(const sf::Event &event)
{
    using graphics::window;

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::setState("menu");

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab)
        editorHUD.setEnabled(!editorHUD.getEnabled());



   // if( editorHUD.selectTile.hovered && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z)
    if( editorHUD.selectTile.hovered && event.type == sf::Event::MouseWheelMoved && event.mouseWheel.x > 1)
        editorHUD.tileSelection();

    if(editorHUD.getEnabled())
        editorHUD.processEvents(event);
}

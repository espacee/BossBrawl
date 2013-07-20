#include "GameState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

GameState::GameState()
{
    playerTexture.loadFromFile("res/img/player.png", sf::IntRect(32 ,0,32 , 32));
    button1text.loadFromFile("res/img/button1.png");
    player.setTexture(playerTexture);
    button1.setTexture(button1text);

    map.ResizeLayer(0,5,5);
    map.FillLayer(0,2);
    map.AddLayer();
    map.ResizeLayer(1,32,18);
    map.FillLayer(1,2);
}

void GameState::OnSet()
{
    graphics::window.setTitle("GAME");
}

void GameState::OnUpdate()
{
    using graphics::window;

    /*** KEYBOARD PLAYER  STUFF ***/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player.move(0, -10);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.move(10, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player.move(0, 10);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.move(-10, 0);

    /*** END KEYBOARD PLAYER STUFF  ***/

    /*** EDITOR MODE WHEN PRESSING CONTROL AND ZQSD/WASD AT THE SAME TIME ***/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
        camera.EditorCamera();


    camera.SetView(1);
    window.clear(sf::Color(0,0,0));
    map.Display();
    window.draw(player);


    camera.SetView(2); // Only Draw after this if you want it on the HUD
    window.draw(button1);
}

void GameState::OnEvent(const sf::Event &event)
{
    using graphics::window;

    if (event.type == sf::Event::Closed)
        window.close();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        window.close();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::SetState("menu");

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F4)
        stateDriver::SetState("editor");

    if(event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == 1)
        camera.ZoomIn();

    if(event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == -1)
        camera.ZoomOut();
}

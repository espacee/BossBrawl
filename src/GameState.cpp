#include "GameState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

GameState::GameState()
{
    playerTexture.loadFromFile("res/img/player.png", sf::IntRect(32 ,0,32 , 32));
    player.setTexture(playerTexture);

    map.ResizeLayer(0,5,5);
    map.FillLayer(0,2);

}

void GameState::OnSet()
{
    graphics::window.setTitle("game");
}

void GameState::OnUpdate()
{
    using graphics::window;

    /*** KEYBOARD PLAYER  STUFF ***/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player.move(0, -7);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.move(7, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player.move(0, 7);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.move(-7, 0);

    /*** END KEYBOARD PLAYER STUFF  ***/

    /*** EDITOR MODE WHEN PRESSING CONTROL AND ZQSD/WASD AT THE SAME TIME ***/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
        camera.EditorCamera();


    //camera
    camera.view.setCenter(player.getPosition().x, player.getPosition().y);

    //Draw Here for the game
    camera.SetView(1);
    window.clear(sf::Color(0,0,0));
    map.Display();
    window.draw(player);

    camera.SetView(2);

}

void GameState::OnEvent(const sf::Event &event)
{
    using graphics::window;

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::RequestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::SetState("menu");

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F4)
        stateDriver::SetState("editor");

    if(event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == 1)
        camera.ZoomIn();

    if(event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == -1)
        camera.ZoomOut();
}

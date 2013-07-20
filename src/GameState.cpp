#include "GameState.hpp"
#include "Camera.hpp"
#include "graphics.hpp"
#include "config.hpp"

GameState::GameState()
{

}

int GameState::Loop()
{

    Camera camera;

    using graphics::window;
    window.setTitle("GAME");

    sf::Texture playerTexture;
    playerTexture.loadFromFile("res/img/player.png", sf::IntRect(32 ,0,32 , 32));
    sf::Sprite player(playerTexture);

    sf::Texture button1text;
    button1text.loadFromFile("res/img/button1.png");
    sf::Sprite button1(button1text);
    

    TileMap map;
    map.ResizeLayer(0,5,5);
    map.FillLayer(0,2);


    map.AddLayer();
    map.ResizeLayer(1,32,18);
    map.FillLayer(1,2);
    

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                return MENU;

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F4)
                return EDITOR;

             if(event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == 1)
                 camera.ZoomIn();

             if(event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == -1)
                 camera.ZoomOut();
        }

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
        window.display();
    }

    return EXIT;
}

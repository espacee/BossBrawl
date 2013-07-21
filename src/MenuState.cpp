#include "MenuState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

void MenuState::onSet()
{
    graphics::window.setTitle("menu");
    btn1.create("Hover me and i move right");
    btn2.create("Press me and i move down");
    btn3.create("Click me");
    btn4.create("Go to GameState");

    btn1.setPosition(10,10);
    btn2.setPosition(10, btn1.getY()+btn1.getHeight()+5);
    btn3.setPosition(graphics::window.getSize().x - btn3.getWidth()-500,10);
    btn4.setPosition(400,400);

}

void MenuState::onUpdate()
{
    using graphics::window;

    window.clear(sf::Color(60,60,60));

    if(btn1.hovered)
        btn1.move(1,0);
    if(btn2.pressed)
        btn2.move(0,1);
    if(btn3.released)
        btn3.setWidth(btn3.getWidth()+20);
    if(btn4.released)
        stateDriver::setState("game");

    btn1.display();
    btn2.display();
    btn3.display();
    btn4.display();

}

void MenuState::onEvent(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::setState("game");

    btn1.processEvents(event);
    btn2.processEvents(event);
    btn3.processEvents(event);
    btn4.processEvents(event);

}

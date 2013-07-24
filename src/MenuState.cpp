#include "MenuState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

void MenuState::onSet()
{
    graphics::window.setTitle("menu");
    graphics::window.setView(graphics::window.getDefaultView());

    playButton.setText("Play");
    playButton.setSize(200,40);
    playButton.setPosition(50,50);

    editorButton.setText("Editor");
    editorButton.setSize(200,40);
    editorButton.setPosition(50,100);
    editorButton.setColorScheme(sf::Color(240,140,60),sf::Color(255,215,90),sf::Color(170,85,60));
    editorButton.setTextColor(sf::Color(80,50,50));

    quitButton.setText("Quit");
    quitButton.setSize(200,40);
    quitButton.setPosition(50,150);
    quitButton.setColorScheme(sf::Color(240,80,130),sf::Color(250,150,180),sf::Color(200,15,50));
    quitButton.setTextColor(sf::Color(50,0,75));
}
void MenuState::onUpdate()
{
    using graphics::window;

    if(playButton.isReleased())
        stateDriver::setState("game");
    if(editorButton.isReleased())
        stateDriver::setState("editor");
    if(quitButton.isReleased())
        stateDriver::requestQuit();

    window.clear(sf::Color(60,60,60));

    playButton.display(window);
    editorButton.display(window);
    quitButton.display(window);
}

void MenuState::onEvent(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    playButton.processEvents(event);
    editorButton.processEvents(event);
    quitButton.processEvents(event);
}

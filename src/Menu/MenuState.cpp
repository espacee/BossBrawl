#include "Menu/MenuState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"

void MenuState::onSet()
{
    graphics::window.setTitle("menu");
    graphics::window.setView(graphics::window.getDefaultView());

    int hc = config::windowWidth / 2, vc = config::windowHeight / 2;

    playButton.setText("Play");
    playButton.setSize(200, 40);
    playButton.setPosition(hc - 100, vc - 70);

    editorButton.setText("Editor");
    editorButton.setSize(200, 40);
    editorButton.setPosition(hc - 100, vc - 20);
    editorButton.setColorScheme(sf::Color(240, 140, 60), sf::Color(255, 215, 90), sf::Color(170, 85, 60));
    editorButton.setTextColor(sf::Color(80, 50, 50));

    quitButton.setText("Quit");
    quitButton.setSize(200, 40);
    quitButton.setPosition(hc - 100, vc + 30);
    quitButton.setColorScheme(sf::Color(240, 80, 130), sf::Color(250, 150, 180), sf::Color(200, 15, 50));
    quitButton.setTextColor(sf::Color(50, 0, 75));

    playButton.enableTransition(true);
    editorButton.enableTransition(true);
    quitButton.enableTransition(true);
    playButton.setTransitionSpeed(0.3);
    editorButton.setTransitionSpeed(0.3);
    quitButton.setTransitionSpeed(0.3);
}

void MenuState::onUpdate()
{
    using graphics::window;
    int hc = config::windowWidth / 2;

    if (playButton.isHovered()) playButton.setX(hc - 80);
    else playButton.setX(hc - 100);

    if (editorButton.isHovered()) editorButton.setX(hc - 80);
    else editorButton.setX(hc - 100);

    if (quitButton.isHovered()) quitButton.setX(hc - 80);
    else quitButton.setX(hc - 100);

    if (playButton.isReleased())
        stateDriver::setState("game");

    if (editorButton.isReleased())
        stateDriver::setState("editor");

    if (quitButton.isReleased())
        stateDriver::requestQuit();

    window.clear(sf::Color(60, 60, 60));

    playButton.display(window);
    editorButton.display(window);
    quitButton.display(window);
}

void MenuState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    playButton.processEvents(event);
    editorButton.processEvents(event);
    quitButton.processEvents(event);
}

#include "Menu/MenuState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"

void MenuState::onSet()
{
    graphics::window.setTitle("menu");
    graphics::window.setView(sf::View(sf::FloatRect(0,0,graphics::window.getSize().x, graphics::window.getSize().y)));

    int hc = graphics::window.getSize().x/ 2, vc = graphics::window.getSize().y / 2;

    playButton.setText("Play");
    playButton.setColorScheme(sf::Color(220, 100, 130), sf::Color(250, 170, 210), sf::Color(200, 15, 50));
    playButton.setSize(200, 40);

    editorButton.setText("Editor");
    editorButton.setSize(200, 40);
    editorButton.setColorScheme(sf::Color(240, 140, 60), sf::Color(255, 215, 90), sf::Color(170, 85, 60));
    editorButton.setTextColor(sf::Color(80, 50, 50));

    optionButton.setText("Options");
    optionButton.setSize(200,40);
    optionButton.setColorScheme(sf::Color(40, 180, 80), sf::Color(180, 230, 30), sf::Color(50,120,100));

    quitButton.setText("Quit");
    quitButton.setSize(200, 40);

    playButton.setPosition(hc-100,vc-160);
    editorButton.setPosition(hc-100,playButton.getY()+playButton.getHeight());
    optionButton.setPosition(hc-100,editorButton.getY()+editorButton.getHeight());
    quitButton.setPosition(hc-100,optionButton.getY()+optionButton.getHeight());

    playButton.enableTransition(true);
    editorButton.enableTransition(true);
    optionButton.enableTransition(true);
    quitButton.enableTransition(true);
    playButton.setTransitionSpeed(0.3);
    editorButton.setTransitionSpeed(0.3);
    optionButton.setTransitionSpeed(0.3);
    quitButton.setTransitionSpeed(0.3);
}

void MenuState::onUpdate()
{
    using graphics::window;

    if(playButton.isHovered())
    {
        playButton.setHeight(150);
    }
    else
    {
        playButton.setHeight(40);
    }

    if(editorButton.isHovered())
    {
        editorButton.setHeight(150);
    }
    else
    {
        editorButton.setHeight(40);
    }

    if(optionButton.isHovered())
    {
        optionButton.setHeight(150);
    }
    else
    {
        optionButton.setHeight(40);
    }

    if(quitButton.isHovered())
    {
        quitButton.setHeight(150);
    }
    else
    {
        quitButton.setHeight(40);
    }

    editorButton.setY(playButton.getY()+playButton.getHeight());
    optionButton.setY(editorButton.getY()+editorButton.getHeight());
    quitButton.setY(optionButton.getY()+optionButton.getHeight());

    if (playButton.isReleased())
        stateDriver::setState("game");

    if (editorButton.isReleased())
        stateDriver::setState("editor");

    if(optionButton.isReleased())
        stateDriver::setState("options");

    if (quitButton.isReleased())
        stateDriver::requestQuit();

    window.clear(sf::Color(65, 60, 60));

    playButton.display(window);
    editorButton.display(window);
    optionButton.display(window);
    quitButton.display(window);
}

void MenuState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    playButton.processEvents(event);
    editorButton.processEvents(event);
    optionButton.processEvents(event);
    quitButton.processEvents(event);
}

#include "OptionsState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"

void OptionsState::onSet()
{
    graphics::window.setTitle("options");

    windowLabel.setFont(graphics::font);
    windowLabel.setCharacterSize(14);
    windowLabel.setPosition(20,40);
    windowLabel.setString("Window size");

    backButton.setText("<< BACK");
    backButton.resetGeometry();
    backButton.setPosition(graphics::window.getSize().x-backButton.getWidth(),0);
    backButton.setCharacterSize(10);

    size1.setText("800x600");
    size2.setText("1000*800");
    size1.setSize(300,35);
    size2.setSize(300,35);

    size1.setPosition(15,60);
    size2.setPosition(15,100);

}

void OptionsState::onUpdate()
{
    using graphics::window;

    if(backButton.isReleased())
    {
        stateDriver::setState("menu");
    }

    if(size1.isReleased())
    {
        graphics::window.setSize(sf::Vector2u(800,600));
        config::windowWidth = 800;
        config::windowHeight = 600;
    }

    if(size2.isReleased())
    {
        graphics::window.setSize(sf::Vector2u(1000,800));
        config::windowWidth = 1000;
        config::windowHeight = 800;
    }

    backButton.setPosition(graphics::window.getSize().x-backButton.getWidth(),0);

    window.clear(sf::Color(65, 60, 60));

    window.draw(windowLabel);
    backButton.display(window);

    size1.display(window);
    size2.display(window);
}

void OptionsState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");

    backButton.processEvents(event);
    size1.processEvents(event);
    size2.processEvents(event);

}

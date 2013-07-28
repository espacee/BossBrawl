#include "OptionsState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"

void OptionsState::onSet()
{
    graphics::window.setTitle("options");
    graphics::window.setView(sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y)));

    windowLabel.setFont(graphics::font);
    windowLabel.setCharacterSize(14);
    windowLabel.setPosition(20, 40);
    windowLabel.setString("Window size");

    backButton.setText("<< BACK");
    backButton.resetGeometry();
    backButton.setPosition(graphics::window.getSize().x - backButton.getWidth(), 0);
    backButton.setCharacterSize(10);

    size1.setText("800x600");
    size2.setText("1000x800");
    size3.setText("1280x720");
    size1.setSize(300, 35);
    size2.setSize(300, 35);
    size3.setSize(300, 35);

    size1.setPosition(15, 60);
    size2.setPosition(15, 100);
    size3.setPosition(15, 140);

}

void OptionsState::onUpdate()
{
    using graphics::window;

    if (backButton.isReleased())
    {
        stateDriver::setState("menu");
    }

    if (size1.isReleased())
    {
        config::resolutionMode = 0;
        graphics::setResolutionMode(0);
    }

    if (size2.isReleased())
    {
        config::resolutionMode = 1;
        graphics::setResolutionMode(1);
    }

    if (size3.isReleased())
    {
        config::resolutionMode = 2;
        graphics::setResolutionMode(2);
    }

    backButton.setPosition(graphics::window.getSize().x - backButton.getWidth(), 0);

    window.clear(sf::Color(65, 60, 60));

    window.draw(windowLabel);
    backButton.display(window);

    size1.display(window);
    size2.display(window);
    size3.display(window);
}

void OptionsState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");

    backButton.processEvents(event);
    size1.processEvents(event);
    size2.processEvents(event);
    size3.processEvents(event);

}

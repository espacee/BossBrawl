#include "OptionsState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"

OptionsState::OptionsState()
{
    addResoButtons();
}

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
}

void OptionsState::onUpdate()
{
    using graphics::window;

    if (backButton.isReleased())
    {
        stateDriver::setState("menu");
    }

    for (decltype(resoButtons)::size_type i = 0; i < resoButtons.size(); ++i)
    {
        TextButton& b = resoButtons[i];

        if (i == config::resolutionMode)
        {
            b.setBackgroundColor(sf::Color::Red);
        }
        else
        {
            b.setBackgroundColor(sf::Color::Blue);
        }

        if (b.isReleased())
        {
            config::resolutionMode = i;
            graphics::setResolutionMode(i);
            break;
        }
    }

    backButton.setPosition(graphics::window.getSize().x - backButton.getWidth(), 0);

    window.clear(sf::Color(65, 60, 60));

    window.draw(windowLabel);
    backButton.display(window);

    for (auto & b : resoButtons)
    {
        b.display(window);
    }
}

void OptionsState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");

    backButton.processEvents(event);

    for (auto & b : resoButtons)
    {
        b.processEvents(event);
    }

}

void OptionsState::addResoButtons()
{
    auto modes = graphics::getResolutionModes();
    int y = 60;

    for (auto m : modes)
    {
        TextButton b;
        b.setText(std::to_string(m.x) + "x" + std::to_string(m.y));
        b.setSize(300, 35);
        b.setPosition(15, y);
        resoButtons.push_back(b);
        y += 40;
    }
}

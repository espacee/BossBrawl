#include "Gui/IconButton.hpp"

#include "Core/graphics.hpp"

IconButton::IconButton()
{
    iconTexture.create(50, 50);
    iconSprite.setTexture(iconTexture, true);
    normalColor = sf::Color(100, 100, 100);
    hoverColor = sf::Color(0, 170, 240);
    pressColor = sf::Color(0, 80, 170);
    backgroundColor = normalColor;
    resetGeometry();
}

void IconButton::resetGeometry()
{
    setSize(iconSprite.getGlobalBounds().width,
            iconSprite.getGlobalBounds().height);
}

void IconButton::setIcon(std::string iconPath)
{
    if (iconTexture.loadFromFile(iconPath))
    {
        iconSprite.setTexture(iconTexture, true);
    }

    resetGeometry();
}

void IconButton::update()
{
    setBackgroundColor(normalColor);

    if (hovered)
        setBackgroundColor(hoverColor);

    if (pressed)
        setBackgroundColor(pressColor);

    if (toggled)
        setBackgroundColor(pressColor);

    iconSprite.setPosition(x + (int)(width / 2 - iconSprite.getGlobalBounds().width / 2),
                           y + (int)(height / 2 - iconSprite.getGlobalBounds().height / 2));
}

void IconButton::display(sf::RenderTarget &target)
{
    Widget::display(target);
    update();
    target.draw(iconSprite);
}

#include "Gui/TextButton.hpp"

#include "Core/graphics.hpp"

TextButton::TextButton()
{
    text.setFont(graphics::font);
    setCharacterSize(16);
    setText(" ");
    horizontalPadding = 40;
    verticalPadding = 20;
    normalColor = sf::Color(100, 100, 100);
    hoverColor = sf::Color(0, 170, 240);
    pressColor = sf::Color(0, 80, 170);
    backgroundColor = normalColor;

    resetGeometry();
}

void TextButton::resetGeometry()
{
    setSize(text.getGlobalBounds().width + horizontalPadding,
            text.getGlobalBounds().height + verticalPadding);
}

void TextButton::setText(std::string string)
{
    text.setString(string);
}

void TextButton::setTextColor(sf::Color textColor)
{
    text.setColor(textColor);
}

void TextButton::setCharacterSize(int new_size)
{
    text.setCharacterSize(new_size);
    text.setOrigin(new_size / 15,
                   new_size / 4);
}

void TextButton::update()
{
    setBackgroundColor(normalColor);

    if (hovered)
        setBackgroundColor(hoverColor);

    if (pressed)
        setBackgroundColor(pressColor);

    if (toggled)
        setBackgroundColor(pressColor);

    text.setPosition(x + (int)(width / 2 - text.getGlobalBounds().width / 2),
                     y + (int)(height / 2 - text.getGlobalBounds().height / 2));
}

void TextButton::display(sf::RenderTarget &target)
{
    Widget::display(target);
    update();

    target.draw(text);
}

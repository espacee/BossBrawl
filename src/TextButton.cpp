#include "TextButton.hpp"

#include "graphics.hpp"

TextButton::TextButton()
{
    text.setFont(graphics::font);
    setCharacterSize(16);
    setText(" ");
    horizontalPadding=40;
    verticalPadding=20;
    normalColor = sf::Color(100,100,100);
    hoverColor = sf::Color(0,170,240);
    pressColor = sf::Color(0,80,170);
    backgroundColor = normalColor;

    resetGeometry();
}

void TextButton::resetGeometry()
{
    setSize(text.getGlobalBounds().width+horizontalPadding,
            text.getGlobalBounds().height+verticalPadding);
    remake();
}

void TextButton::setGeometry(int new_x, int new_y, int new_width, int new_height)
{
    x = new_x;
    y = new_y;
    width = new_width;
    height = new_height;
    remake();
}

void TextButton::setSize(int new_width, int new_height)
{
    width = new_width;
    height = new_height;
    remake();
}

void TextButton::setWidth(int new_width)
{
    width = new_width;
    remake();
}

void TextButton::setHeight(int new_height)
{
    height = new_height;
    remake();
}

void TextButton::setPosition(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
    remake();
}

void TextButton::setX(int new_x)
{
    x = new_x;
    remake();
}

void TextButton::setY(int new_y)
{
    y = new_y;
    remake();
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
    text.setOrigin(new_size/15,
                   new_size/4);
}

void TextButton::remake()
{
    Widget::remake();
    text.setPosition(x+(int)(width/2-text.getGlobalBounds().width/2),
                     y+(int)(height/2-text.getGlobalBounds().height/2));
}

void TextButton::update()
{
    setBackgroundColor(normalColor);

    if(hovered)
        setBackgroundColor(hoverColor);

    if(pressed)
        setBackgroundColor(pressColor);
}

void TextButton::display(sf::RenderTarget &target)
{
    Widget::display(target);
    update();

    target.draw(text);
}

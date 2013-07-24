#include "IconButton.hpp"

#include "graphics.hpp"

IconButton::IconButton()
{
    iconTexture.create(50,50);
    iconSprite.setTexture(iconTexture, true);
    normalColor = sf::Color(100,100,100);
    hoverColor = sf::Color(0,170,240);
    pressColor = sf::Color(0,80,170);
    backgroundColor = normalColor;

    resetGeometry();
}

void IconButton::resetGeometry()
{
    setSize(iconSprite.getGlobalBounds().width,
            iconSprite.getGlobalBounds().height);
    remake();
}

void IconButton::setGeometry(int new_x, int new_y, int new_width, int new_height)
{
    x = new_x;
    y = new_y;
    width = new_width;
    height = new_height;
    remake();
}

void IconButton::setSize(int new_width, int new_height)
{
    width = new_width;
    height = new_height;
    remake();
}

void IconButton::setWidth(int new_width)
{
    width = new_width;
    remake();
}

void IconButton::setHeight(int new_height)
{
    height = new_height;
    remake();
}

void IconButton::setPosition(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
    remake();
}

void IconButton::setX(int new_x)
{
    x = new_x;
    remake();
}

void IconButton::setY(int new_y)
{
    y = new_y;
    remake();
}

void IconButton::setIcon(std::string iconPath)
{

    if(iconTexture.loadFromFile(iconPath))
    {
        iconSprite.setTexture(iconTexture, true);
    }

    resetGeometry();
}

void IconButton::remake()
{
    Widget::remake();
    iconSprite.setPosition(x+(int)(width/2-iconSprite.getGlobalBounds().width/2),
                           y+(int)(height/2-iconSprite.getGlobalBounds().height/2));
}

void IconButton::update()
{
    setBackgroundColor(normalColor);

    if(hovered)
        setBackgroundColor(hoverColor);

    if(pressed)
        setBackgroundColor(pressColor);
}

void IconButton::display(sf::RenderTarget &target)
{
    Widget::display(target);
    update();

    target.draw(iconSprite);
}

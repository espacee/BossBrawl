#include "Widget.hpp"

#include "graphics.hpp"

Widget::Widget()
{
    x=0;
    y=0;
    width=50;
    height=50;
    normalColor = sf::Color(100,100,100);
    hoverColor = sf::Color(100,100,100);
    pressColor = sf::Color(100,100,100);
    backgroundColor = normalColor;
    hovered = false;
    pressed = false;
    released = false;

    remake();
}

void Widget::setGeometry(int new_x, int new_y, int new_width, int new_height)
{
    x = new_x;
    y = new_y;
    width = new_width;
    height = new_height;
    remake();
}

void Widget::setSize(int new_width, int new_height)
{
    width = new_width;
    height = new_height;
    remake();
}

void Widget::setWidth(int new_width)
{
    width = new_width;
    remake();
}

void Widget::setHeight(int new_height)
{
    height = new_height;
    remake();
}

void Widget::setPosition(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
    remake();
}

void Widget::setX(int new_x)
{
    x = new_x;
    remake();
}

void Widget::setY(int new_y)
{
    y = new_y;
    remake();
}

int Widget::getWidth() const
{
    return width;
}

int Widget::getHeight() const
{
    return height;
}

int Widget::getX() const
{
    return x;
}

int Widget::getY() const
{
    return y;
}


void Widget::setBackgroundColor(sf::Color new_color)
{
    backgroundColor = new_color;
    background.setFillColor(backgroundColor);
}

sf::Color Widget::getBackgroundColor() const
{
    return backgroundColor;
}

void Widget::setColorScheme(sf::Color newNormalColor, sf::Color newHoverColor, sf::Color newPressColor)
{
    normalColor = newNormalColor;
    hoverColor = newHoverColor;
    pressColor = newPressColor;
}

void Widget::remake()
{
    background.setPosition(x,y);
    background.setSize(sf::Vector2f(width, height));
}

void Widget::processEvents(const sf::Event &event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        if
        (
            event.mouseMove.x > x &&
            event.mouseMove.y > y &&
            event.mouseMove.x < x + width &&
            event.mouseMove.y < y + height
        )
        {
            hovered = true;
        }
        else
        {
            hovered = false;
        }
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if(hovered)
            pressed = true;
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        pressed = false;
        if(hovered)
            released = true;
    }
    else
    {
        released = false;
    }
}

void Widget::update()
{
    released = false;
}

void Widget::display(sf::RenderTarget& target)
{
    update();

    target.draw(background);
}

bool Widget::isHovered() const
{
    return hovered;
}
bool Widget::isPressed() const
{
    return pressed;
}

bool Widget::isReleased() const
{
    return released;
}

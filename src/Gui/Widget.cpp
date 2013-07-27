#include "Gui/Widget.hpp"

#include "Core/graphics.hpp"

Widget::Widget()
{
    x = targetX = 0;
    y = targetY = 0;
    width = targetWidth = 50;
    height = targetHeight = 50;
    normalColor = sf::Color(100, 100, 100);
    hoverColor = sf::Color(100, 100, 100);
    pressColor = sf::Color(100, 100, 100);
    backgroundColor = targetBackgroundColor = normalColor;
    setBackgroundColor(normalColor);
    active = true;
    toggleable = false;
    hovered = false;
    pressed = false;
    released = false;
    toggled = false;
    transitionEnabled = false;
    transitionSpeed = 1;
}

void Widget::setGeometry(int new_x, int new_y, int new_width, int new_height)
{
    targetX = new_x;
    targetY = new_y;
    targetWidth = new_width;
    targetHeight = new_height;

    if (!transitionEnabled)
    {
        x = new_x;
        y = new_y;
        width = new_width;
        height = new_height;
    }
}

void Widget::setSize(int new_width, int new_height)
{
    targetWidth = new_width;
    targetHeight = new_height;

    if (!transitionEnabled)
    {
        width = new_width;
        height = new_height;
    }
}

void Widget::setWidth(int new_width)
{
    targetWidth = new_width;

    if (!transitionEnabled)
    {
        width = new_width;
    }
}

void Widget::setHeight(int new_height)
{
    targetHeight = new_height;

    if (!transitionEnabled)
    {
        height = new_height;
    }
}

void Widget::setPosition(int new_x, int new_y)
{
    targetX = new_x;
    targetY = new_y;

    if (!transitionEnabled)
    {
        x = new_x;
        y = new_y;
    }
}

void Widget::setX(int new_x)
{
    targetX = new_x;

    if (!transitionEnabled)
    {
        x = new_x;
    }
}

void Widget::setY(int new_y)
{
    targetY = new_y;

    if (!transitionEnabled)
    {
        y = new_y;
    }
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
    targetBackgroundColor = new_color;

    if (!transitionEnabled)
    {
        backgroundColor = new_color;
    }

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

void Widget::processEvents(const sf::Event &event)
{
    if (active)
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
            if (hovered)
                pressed = true;
        }

        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            pressed = false;
            if (hovered)
            {
                released = true;

                if (toggleable)
                {
                    toggled = !toggled;
                }
            }
            hovered = false;
        }
        else
        {
            released = false;
        }
    }
    else
    {
        hovered = false;
        pressed = false;
        released = false;
        toggled = false;
    }
}

void Widget::update()
{
    released = false;

    x += (targetX - x) * transitionSpeed;
    y += (targetY - y) * transitionSpeed;
    width += (targetWidth - width) * transitionSpeed;
    height += (targetHeight - height) * transitionSpeed;
    backgroundColor = sf::Color(backgroundColor.r + (targetBackgroundColor.r - backgroundColor.r) * transitionSpeed,
                                backgroundColor.g + (targetBackgroundColor.g - backgroundColor.g) * transitionSpeed,
                                backgroundColor.b + (targetBackgroundColor.b - backgroundColor.b) * transitionSpeed);

    background.setPosition(x, y);
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(backgroundColor);
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

bool Widget::isToggled() const
{
    return toggled;
}

bool Widget::isActive() const
{
    return active;
}

void Widget::setToggleable(bool yesno)
{
    toggleable = yesno;
}

void Widget::setActive(bool yesno)
{
    active = yesno;
}

void Widget::setTransitionSpeed(float new_transitionSpeed)
{
    transitionSpeed = new_transitionSpeed;
}

void Widget::enableTransition(bool yesno)
{
    transitionEnabled = yesno;
}

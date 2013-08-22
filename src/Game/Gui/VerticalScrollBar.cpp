#include "VerticalScrollBar.hpp"

#include "IconButton.hpp"

VerticalScrollBar::VerticalScrollBar()
{

    topArrowButton.setIcon("res/img/GUI/scrollBarTop.png");
    downArrowButton.setIcon("res/img/GUI/scrollBarBot.png");
    liftButton.setIcon("res/img/GUI/scrollBarLift.png");
    liftButton.setWidth(12);
    liftButton.setHeight(80);

    setSize(14, topArrowButton.getHeight() + downArrowButton.getHeight() + liftButton.getHeight() + 2);
    update();
    liftButton.setPosition(2, liftStart);
    mouse = 0;
    pos = 0;

    mouseWheelAllowed = false;
}

void VerticalScrollBar::update()
{
    setWidth(14);

    topArrowButton.setPosition(getX() + 2, getY() + 1);
    downArrowButton.setPosition(getX() + 2, getY() + getHeight() - 11);
    liftStart = topArrowButton.getY() + topArrowButton.getHeight() + 1;
    liftEnd = downArrowButton.getY() - 1 - liftButton.getHeight();

    liftButton.setPosition(getX() + 1, liftStart + mouse);

    if (liftButton.getY() < liftStart)
    {
        liftButton.setY(liftStart);
        mouse = 0;
    }

    if (liftButton.getY() > liftEnd)
    {
        liftButton.setY(liftEnd);
        mouse = liftEnd - liftStart;
    }

    if (downArrowButton.isPressed())
    {
        mouse += 5;
    }

    if (topArrowButton.isPressed())
    {
        mouse -= 5;
    }

    pos = (float)(liftButton.getY() - liftStart) / (float)(liftEnd - liftStart);

    bar.setSize(getWidth() - 4, getHeight() - 2);
    bar.setBackgroundColor(sf::Color(30, 30, 30));
    bar.setPosition(getX() + 2, getY() + 1);
}

void VerticalScrollBar::display(sf::RenderTarget &target)
{
    Widget::display(target);
    update();

    bar.display(target);
    topArrowButton.display(target);
    downArrowButton.display(target);
    liftButton.display(target);
}

void VerticalScrollBar::processEvents(const sf::Event &event)
{
    Widget::processEvents(event);
    bar.processEvents(event);
    topArrowButton.processEvents(event);
    downArrowButton.processEvents(event);
    liftButton.processEvents(event);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (liftButton.isPressed())
        {
            offsetY = event.mouseButton.y - liftButton.getY();
        }
    }

    if (event.type == sf::Event::MouseMoved)
    {
        if (liftButton.isPressed())
        {
            mouse = event.mouseMove.y - offsetY - liftStart;
        }
    }

    if (event.type == sf::Event::MouseWheelMoved)
    {
        if (mouseWheelAllowed)
            mouse -= 10 * event.mouseWheel.delta;
    }
}

float VerticalScrollBar::getPos()
{
    return pos;
}

#include "ScrollArea.hpp"

ScrollArea::ScrollArea()
{
    setSize(200, 200);
    setBackgroundColor(sf::Color(40, 40, 40));
    vScrollBar.setSize(15, getHeight());
    vScrollBar.setPosition(getX() + getWidth() - vScrollBar.getWidth() - 5, getY());
    childSet = false;
}

void ScrollArea::update()
{
    vScrollBar.setHeight(getHeight());
    vScrollBar.setPosition(getX() + getWidth() - vScrollBar.getWidth() - 5, getY());

    if (isHovered())
        vScrollBar.mouseWheelAllowed = true;
    else
        vScrollBar.mouseWheelAllowed = false;
}

void ScrollArea::display(sf::RenderTarget &target)
{
    Widget::display(target);
    update();

    vScrollBar.display(target);
}

void ScrollArea::processEvents(const sf::Event &event)
{
    Widget::processEvents(event);
    vScrollBar.processEvents(event);

}

void ScrollArea::setChildWidget(Widget* new_childWidget)
{
    childSet = true;
}

Widget* ScrollArea::getChildWidget()
{

}


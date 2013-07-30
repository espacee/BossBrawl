#ifndef SCROLLAREA_HPP
#define SCROLLAREA_HPP

#include "Gui/Widget.hpp"
#include "Gui/VerticalScrollBar.hpp"

class ScrollArea : public Widget
{
public:
    ScrollArea();

    void update();
    void display(sf::RenderTarget &target);
    void processEvents(const sf::Event &event);
    void setChildWidget(Widget* new_childWidget);
    Widget* getChildWidget();

    VerticalScrollBar vScrollBar;
private:
    bool childSet;
};

#endif // SCROLLAREA_HPP

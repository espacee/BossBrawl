#ifndef SCROLLBAR_HPP
#define SCROLLBAR_HPP

#include "Gui/Widget.hpp"
#include "Gui/IconButton.hpp"

class VerticalScrollBar : public Widget
{
public:
    VerticalScrollBar();

    void update();
    void display(sf::RenderTarget &target);
    void processEvents(const sf::Event &event);
    float getPos();

private:
    Widget bar;
    IconButton topArrowButton;
    IconButton downArrowButton;
    IconButton liftButton;
    int liftStart, liftEnd, liftPos, mouse, offsetY;
    float pos;
};

#endif // SCROLLBAR_HPP

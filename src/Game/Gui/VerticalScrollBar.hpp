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

    bool mouseWheelAllowed;
    Widget bar;
    IconButton topArrowButton;
    IconButton downArrowButton;
    IconButton liftButton;
private:
    int liftStart, liftEnd, mouse, offsetY;
    float pos;
};

#endif // SCROLLBAR_HPP

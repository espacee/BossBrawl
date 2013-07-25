#ifndef TEXTBUTTON_HPP
#define TEXTBUTTON_HPP

#include "Gui/Widget.hpp"

/**
 * @brief A button that has text
 */
class TextButton : public Widget
{
public:
    TextButton();

    void resetGeometry();
    void setGeometry(int new_x, int new_y, int new_width, int new_height);
    void setSize(int new_width, int new_height);
    void setWidth(int new_width);
    void setHeight(int new_height);
    void setPosition(int new_x, int new_y);
    void setX(int new_x);
    void setY(int new_y);

    void setText(std::string string);
    void setTextColor(sf::Color textColor);
    void setCharacterSize(int new_size);

    void remake();
    void update();
    void display(sf::RenderTarget &target);

private:
    int horizontalPadding, verticalPadding;
    sf::Text text;
};

#endif // TEXTBUTTON_HPP

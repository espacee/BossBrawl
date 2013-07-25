#ifndef GUI_TEXTBUTTON_HPP
#define GUI_TEXTBUTTON_HPP

#include "Gui/Widget.hpp"

/**
 * @brief A button that has text
 */
class TextButton : public Widget
{
public:
    TextButton();

    void resetGeometry();

    void setText(std::string string);
    void setTextColor(sf::Color textColor);
    void setCharacterSize(int new_size);

    void update();
    void display(sf::RenderTarget &target);

private:
    int horizontalPadding, verticalPadding;
    sf::Text text;
};

#endif // GUI_TEXTBUTTON_HPP

#ifndef ICONBUTTON_HPP
#define ICONBUTTON_HPP

#include "Widget.hpp"

/**
 * @brief A button that has an icon
 */
class IconButton : public Widget
{
public:
    IconButton();

    void resetGeometry();
    void setGeometry(int new_x, int new_y, int new_width, int new_height);
    void setSize(int new_width, int new_height);
    void setWidth(int new_width);
    void setHeight(int new_height);
    void setPosition(int new_x, int new_y);
    void setX(int new_x);
    void setY(int new_y);

    void setText(std::string string);
    void setCharacterSize(int new_size);

    void setIcon(std::string iconPath);

    void remake();
    void update();
    void display(sf::RenderTarget &target);

private:

    sf::Texture iconTexture;
    sf::Sprite iconSprite;
};

#endif // ICONBUTTON_HPP

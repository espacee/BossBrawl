#ifndef GUI_ICONBUTTON_HPP
#define GUI_ICONBUTTON_HPP

#include "Gui/Widget.hpp"

/**
 * @brief A button that has an icon
 */
class IconButton : public Widget
{
public:
    IconButton();

    void resetGeometry();

    void setText(std::string string);
    void setCharacterSize(int new_size);

    void setIcon(std::string iconPath);

    void update();
    void display(sf::RenderTarget &target);

private:

    sf::Texture iconTexture;
    sf::Sprite iconSprite;
};

#endif // GUI_ICONBUTTON_HPP

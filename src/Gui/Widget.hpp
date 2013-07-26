#ifndef GUI_WIDGET_HPP
#define GUI_WIDGET_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief Base class for GUI widgets
 */
class Widget
{
public:
    Widget();

    void setGeometry(int new_x, int new_y, int new_width, int new_height);
    void setSize(int new_width, int new_height);
    void setWidth(int new_width);
    void setHeight(int new_height);
    void setPosition(int new_x, int new_y);
    void setX(int new_x);
    void setY(int new_y);

    int getWidth() const;
    int getHeight() const;
    int getX() const;
    int getY() const;

    void setBackgroundColor(sf::Color new_color);
    sf::Color getBackgroundColor() const;
    void setColorScheme(sf::Color newNormalColor, sf::Color newHoverColor, sf::Color newPressColor);

    void processEvents(const sf::Event &event);
    void update();
    void display(sf::RenderTarget& target);

    bool isHovered() const;
    bool isPressed() const;
    bool isReleased() const;
    bool isToggled() const;
    bool isActive() const;
    void setToggleable(bool yesno);
    void setActive(bool yesno);

    void setTransitionSpeed(float new_transitionSpeed);
    void enableTransition(bool yesno);

protected:
    int x, y, width, height;
    int targetX, targetY, targetWidth, targetHeight;
    sf::Color backgroundColor, normalColor, hoverColor, pressColor;
    sf::Color targetBackgroundColor;
    sf::RectangleShape background;
    bool active, toggleable, hovered, pressed, released, toggled, transitionEnabled;
    float transitionSpeed;
};

#endif // GUI_WIDGET_HPP

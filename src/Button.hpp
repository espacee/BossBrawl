#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(std::string string="");

    void create(std::string string="");
    void setText(std::string string);
    void setCharacterSize(unsigned int characterSize);
    void setIcon(std::string iconPath);
    void removeIcon();

    void resetGeometry();
    void setGeometry(int new_x, int new_y, unsigned int new_width, unsigned int new_height);
    void setSize(unsigned int new_width, unsigned int new_height);
    void setWidth(unsigned int new_width);
    void setHeight(unsigned int new_height);
    void setPosition(int new_x, int new_y);
    void move(int x_offset, int y_offset);
    void setX(int new_x);
    void setY(int new_y);

    sf::Vector2i getSize() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    sf::Vector2i getPosition() const;
    int getX() const;
    int getY() const;

    void processEvents(const sf::Event &event);
    void display();

    bool hovered, pressed, released;

private:
    void update();

    sf::RectangleShape background;
    sf::Text text;
    int x, y;
    unsigned int width, height;
    int horizontalPadding, verticalPadding;
    sf::Color backgroundColor;
    sf::Texture iconTexture;
    sf::Sprite iconSprite;
    bool icon;
};

#endif // BUTTON_HPP

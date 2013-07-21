#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button
{

public:
    Button(std::string string="");

    void Create(std::string string="");
    void SetText(std::string string);
    void SetCharacterSize(unsigned int characterSize);

    void ResetGeometry();
    void SetGeometry(int new_x, int new_y, unsigned int new_width, unsigned int new_height);
    void SetSize(unsigned int new_width, unsigned int new_height);
    void SetWidth(unsigned int new_width);
    void SetHeight(unsigned int new_height);
    void SetPosition(int new_x, int new_y);
    void Move(int x_offset, int y_offset);
    void SetX(int new_x);
    void SetY(int new_y);

    sf::Vector2i GetSize() const;
    unsigned int getWidth() const;
    unsigned int GetHeight() const;
    sf::Vector2i GetPosition() const;
    int GetX() const;
    int GetY() const;

    void ProcessEvents(const sf::Event &event);
    void Display();
private:
    void ResizeTexture();

    sf::RenderTexture renderTexture;
    sf::Text text;
    int x, y;
    unsigned int width, height;
    int horizontalPadding, verticalPadding;
    sf::Color background;
};

#endif // BUTTON_HPP

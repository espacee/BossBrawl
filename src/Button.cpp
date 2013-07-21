#include "Button.hpp"

#include "graphics.hpp"

Button::Button(std::string string)
{
    SetCharacterSize(16);

    horizontalPadding = 40;
    verticalPadding=20;

    // HARDCODED FIX FOR THE TEXT CUTOFF PROBLEM
    text.setFont(graphics::font);
    text.setOrigin(text.getCharacterSize()/15,
                   text.getCharacterSize()/4);

    Create(string);

}

void Button::Create(std::string string)
{
    SetText(string);

    ResetGeometry();
}

void Button::SetText(std::string string)
{
    text.setString(string);
}

void Button::SetCharacterSize(unsigned int characterSize)
{
    text.setCharacterSize(characterSize);
}

void Button::ResetGeometry()
{
    if(text.getString()=="")
    {
        SetSize(30,30);
    }
    else
    {
        SetSize(text.getGlobalBounds().width+horizontalPadding,
                text.getGlobalBounds().height+verticalPadding);
    }
}

void Button::SetGeometry(int new_x, int new_y, unsigned int new_width, unsigned int new_height)
{
    SetPosition(new_x,new_y);
    SetSize(new_width, new_height);

}

void Button::SetSize(unsigned int new_width, unsigned int new_height)
{
    if(new_width>0)
    width = new_width;

    if(new_height>0)
    height = new_height;

    ResizeTexture();
}

void Button::SetWidth(unsigned int new_width)
{
    if(new_width>0)
    width = new_width;

    ResizeTexture();
}

void Button::SetHeight(unsigned int new_height)
{
    if(new_height>0)
    height = new_height;

    ResizeTexture();
}

void Button::SetPosition(int new_x, int new_y)
{
    SetX(new_x);
    SetY(new_y);
}

void Button::Move(int x_offset, int y_offset)
{
    x+= x_offset;
    y+= y_offset;
}

void Button::SetX(int new_x)
{
    x = new_x;
}

void Button::SetY(int new_y)
{
    y = new_y;
}

sf::Vector2i Button::GetSize() const
{
    return sf::Vector2i(width, height);
}

unsigned int Button::getWidth() const
{
    return width;
}

unsigned int Button::GetHeight() const
{
    return height;
}

sf::Vector2i Button::GetPosition() const
{
    return sf::Vector2i(x,y);
}

int Button::GetX() const
{
    return x;
}

int Button::GetY() const
{
    return y;
}

void Button::ResizeTexture()
{
    renderTexture.create(width,
                         height);

    text.setPosition((int)(width/2-text.getGlobalBounds().width/2),
                     (int)(height/2-text.getGlobalBounds().height/2));
}

void Button::Display()
{
    renderTexture.clear(sf::Color::Red);

    renderTexture.draw(text);

    renderTexture.display();

    sf::Sprite renderSprite(renderTexture.getTexture());
    renderSprite.setPosition(x,y);
    graphics::window.draw(renderSprite);
}

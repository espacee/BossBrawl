#include "Button.hpp"

#include "graphics.hpp"

Button::Button(std::string string)
{
    text.setFont(graphics::font);
    setCharacterSize(16);

    horizontalPadding = 40;
    verticalPadding=20;

    create(string);
}

void Button::create(std::string string)
{

    setPosition(0,0);
    hovered = pressed = released = false;

    setText(string);

    resetGeometry();
}

void Button::setText(std::string string)
{
    text.setString(string);
}

void Button::setCharacterSize(unsigned int characterSize)
{
    text.setCharacterSize(characterSize);

    // HARDCODED FIX FOR THE TEXT CUTOFF PROBLEM
    text.setOrigin(text.getCharacterSize()/15,
                   text.getCharacterSize()/4);
}

void Button::resetGeometry()
{
    if(text.getString()=="")
    {
        setSize(30,30);
    }
    else
    {
        setSize(text.getGlobalBounds().width+horizontalPadding,
                text.getGlobalBounds().height+verticalPadding);
    }
}

void Button::setGeometry(int new_x, int new_y, unsigned int new_width, unsigned int new_height)
{
    setPosition(new_x,new_y);
    setSize(new_width, new_height);

}

void Button::setSize(unsigned int new_width, unsigned int new_height)
{
    if(new_width>0)
    width = new_width;

    if(new_height>0)
    height = new_height;

    update();
}

void Button::setWidth(unsigned int new_width)
{
    if(new_width>0)
    width = new_width;

    update();
}

void Button::setHeight(unsigned int new_height)
{
    if(new_height>0)
    height = new_height;

    update();
}

void Button::setPosition(int new_x, int new_y)
{
    x = new_x;
    y = new_y;

    update();
}

void Button::move(int x_offset, int y_offset)
{
    x+= x_offset;
    y+= y_offset;

    update();
}

void Button::setX(int new_x)
{
    x = new_x;

    update();
}

void Button::setY(int new_y)
{
    y = new_y;

    update();
}

sf::Vector2i Button::getSize() const
{
    return sf::Vector2i(width, height);
}

unsigned int Button::getWidth() const
{
    return width;
}

unsigned int Button::getHeight() const
{
    return height;
}

sf::Vector2i Button::getPosition() const
{
    return sf::Vector2i(x,y);
}

int Button::getX() const
{
    return x;
}

int Button::getY() const
{
    return y;
}

void Button::update()
{
    background.setSize(sf::Vector2f(width,
                                    height));
    background.setPosition(x,y);

    text.setPosition(x+(int)(width/2-text.getGlobalBounds().width/2),
                     y+(int)(height/2-text.getGlobalBounds().height/2));
}

void Button::processEvents(const sf::Event &event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        if(event.mouseMove.x>x &&
           event.mouseMove.y>y &&
           event.mouseMove.x<x+width &&
           event.mouseMove.y<y+height)
        {
            hovered = true;
        }
        else
        {
            hovered = false;
        }
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if(hovered)
            pressed = true;
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        pressed = false;
        if(hovered)
            released = true;
    }
    else
    {
        released = false;
    }
}

void Button::display()
{
    backgroundColor = sf::Color(100,100,100);

    if(hovered)
        backgroundColor = sf::Color(0,170,240);

    if(pressed)
        backgroundColor = sf::Color(0,80,170);

    released = false;

    background.setFillColor(backgroundColor);
    graphics::window.draw(background);
    graphics::window.draw(text);
}

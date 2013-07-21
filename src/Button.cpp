#include "Button.hpp"

#include "graphics.hpp"

Button::Button(std::string string)
{
    text.setFont(graphics::font);
    setCharacterSize(16);

    horizontalPadding = 40;
    verticalPadding=20;

    setPosition(0,0);

    background = sf::Color::Red;
    hover = pressed = false;

    create(string);
}

void Button::create(std::string string)
{
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

    resizeTexture();
}

void Button::setWidth(unsigned int new_width)
{
    if(new_width>0)
    width = new_width;

    resizeTexture();
}

void Button::setHeight(unsigned int new_height)
{
    if(new_height>0)
    height = new_height;

    resizeTexture();
}

void Button::setPosition(int new_x, int new_y)
{
    setX(new_x);
    setY(new_y);
}

void Button::move(int x_offset, int y_offset)
{
    x+= x_offset;
    y+= y_offset;
}

void Button::setX(int new_x)
{
    x = new_x;
}

void Button::setY(int new_y)
{
    y = new_y;
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

void Button::resizeTexture()
{
    renderTexture.create(width,
                         height);

    text.setPosition((int)(width/2-text.getGlobalBounds().width/2),
                     (int)(height/2-text.getGlobalBounds().height/2));
}

void Button::processEvents(const sf::Event &event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        if(event.mouseMove.x>x && event.mouseMove.x<x+width && event.mouseMove.y>y && event.mouseMove.y<y+height)
        {
            hover =true;
        }
        else
        {
            hover = false;
        }
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        pressed = true;
    }
    else
    {
        pressed =false;
    }

    if(hover)
    {
        if(pressed)
        {
            background = sf::Color::Green;
        }
        else
        {
            background = sf::Color::Blue;
        }
    }
    else
    {
        background = sf::Color::Red;
    }
}

void Button::display()
{
    renderTexture.clear(background);

    renderTexture.draw(text);

    renderTexture.display();

    sf::Sprite renderSprite(renderTexture.getTexture());
    renderSprite.setPosition(x,y);

    graphics::window.draw(renderSprite);
}

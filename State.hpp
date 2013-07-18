#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

enum { EXIT=-1,
       MENU=0,
       GAME=1};

class State
{
public :
    virtual int Loop (sf::RenderWindow &w) = 0;
};

#endif // STATE_HPP

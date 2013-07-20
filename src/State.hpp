#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

enum { EXIT=-1,
       MENU=0,
       GAME=1,
       EDITOR=2
     };

class State
{
public :
    virtual int Loop () = 0;
    virtual ~State() {}
};

#endif // STATE_HPP

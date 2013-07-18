#ifndef SCREENGAMELOOP_H
#define SCREENGAMELOOP_H

#include <SFML/Graphics.hpp>

class ScreenGameLoop
{
public:
	ScreenGameLoop();
	void Gameloop();
private:
    sf::RenderWindow Screen;
	
};

#endif //!SCREENGAMELOOP_H

#ifndef CORE_GRAPHICS_HPP
#define CORE_GRAPHICS_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief Graphics module
 */
namespace graphics
{

extern sf::RenderWindow window;
extern sf::Font font;

void init();
void setResolution(int width, int height);

}

#endif // CORE_GRAPHICS_HPP

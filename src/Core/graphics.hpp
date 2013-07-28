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
void setResolutionMode(int index);

}

#endif // CORE_GRAPHICS_HPP

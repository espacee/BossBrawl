#ifndef CORE_GRAPHICS_HPP
#define CORE_GRAPHICS_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief Graphics module
 */
namespace graphics
{

extern sf::RenderWindow window;
extern sf::Font fontarial;
extern sf::Font fontbasiclight;

void init();
void setResolutionMode(unsigned int index);
void setDesktopResolution();
const std::vector<sf::Vector2i>& getResolutionModes();

}

#endif // CORE_GRAPHICS_HPP

#ifndef UTIL_VIEW_HPP
#define UTIL_VIEW_HPP

#include <SFML/Graphics.hpp>

void moveViewTowardsPoint(sf::View& view, float x, float y, float speed);
void moveViewTowardsPoint(sf::View& view, sf::Vector2f pos, float speed);

#endif // UTIL_VIEW_HPP

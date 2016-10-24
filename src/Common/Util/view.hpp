#ifndef UTIL_VIEW_HPP
#define UTIL_VIEW_HPP

#include <SFML/Graphics.hpp>

namespace util {

void moveViewTowardsPoint(sf::View &view, sf::Vector2f point, float speed);
void gameViewerMove(sf::View &view, sf::Vector2f direction, float speed);

}

#endif // UTIL_VIEW_HPP

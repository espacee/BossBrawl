#ifndef UTIL_VIEW_HPP
#define UTIL_VIEW_HPP

#include <SFML/Graphics.hpp>

namespace util {

void moveViewTowardsPoint(sf::View &view, sf::Vector2f point, float speed);
void mapViewerUpdate(sf::View &view, sf::Vector2f factor);

}

#endif // UTIL_VIEW_HPP

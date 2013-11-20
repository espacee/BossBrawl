#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <SFML/Graphics/Rect.hpp>

namespace util {

// Test if a point is in an Axis Aligned Bounding Box
bool hitTest(sf::Vector2f point, sf::FloatRect AABB);
// Test collision beetween two given Axis Aligned Bounding Boxes
bool hitTest(sf::FloatRect A, sf::FloatRect B);
// Test if a point is in a circle
bool hitTest(sf::Vector2f point, sf::Vector2f circleCenter, int circleRadius);
// Test collision beetween two circles
bool hitTest(sf::Vector2f Acenter, int Aradius, sf::Vector2f Bcenter, int Bradius);

}

#endif // COLLISION_HPP

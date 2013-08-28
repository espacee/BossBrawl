#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

bool hitTest(sf::Vector2f point, sf::FloatRect AABB); // Test if a point is in an Axis Aligned Bounding Box

bool hitTest(sf::FloatRect A, sf::FloatRect B); // Test collision beetween two given Axis Aligned Bounding Boxes

bool hitTest(sf::Vector2f point, sf::Vector2f circleCenter, int circleRadius); // Test if a point is in a circle;

bool hitTest(sf::Vector2f Acenter, int Aradius, sf::Vector2f Bcenter, int Bradius); // Test collision beetween two circles

#endif // COLLISION_H

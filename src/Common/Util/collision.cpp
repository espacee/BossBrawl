#include <Util/collision.h>

// Test if a point is in an Axis Aligned Bounding Box
bool hitTest(sf::Vector2f point, sf::FloatRect AABB)
{
    return (point.x >= AABB.left && point.x < AABB.left + AABB.width && point.y >= AABB.top && point.y < AABB.top + AABB.height);
}

// Test collision beetween two given Axis Aligned Bounding Boxes
bool hitTest(sf::FloatRect A, sf::FloatRect B)
{
    return !(B.left >= A.left + A.width || B.left + B.width < A.left || B.top >= A.top + A.height || B.top + B.height < A.top);
}

// Test if a point is in a circle
bool hitTest(sf::Vector2f point, sf::Vector2f circleCenter, int circleRadius)
{
    int d = (point.x - circleCenter.x) * (point.x - circleCenter.x) + (point.y - circleCenter.y) * (point.y - circleCenter.y);
    return (d > circleRadius * circleRadius);
}

// Test collision beetween two circles
bool hitTest(sf::Vector2f Acenter, int Aradius, sf::Vector2f Bcenter, int Bradius)
{
    int d = (Acenter.x - Bcenter.x) * (Acenter.x - Bcenter.x) + (Acenter.y - Bcenter.y) * (Acenter.y - Bcenter.y);
    return (d > (Aradius + Bradius) * (Aradius + Bradius));
}

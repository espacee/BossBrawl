#include "Util/view.hpp"

void moveViewTowardsPoint(sf::View& view, float x, float y, float speed)
{
    view.setCenter((int)(view.getCenter().x + (x - view.getCenter().x) * speed),
                   (int)(view.getCenter().y + (y - view.getCenter().y) * speed));
}

void moveViewTowardsPoint(sf::View& view, sf::Vector2f pos, float speed)
{
    view.setCenter((int)(view.getCenter().x + (pos.x - view.getCenter().x) * speed),
                   (int)(view.getCenter().y + (pos.y - view.getCenter().y) * speed));
}

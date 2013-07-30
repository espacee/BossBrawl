#include "Util/view.hpp"

void moveViewTowardsPoint(sf::View& view, float x, float y, float speed)
{
    view.setCenter((int)(view.getCenter().x + (x - view.getCenter().x) * speed),
                   (int)(view.getCenter().y + (y - view.getCenter().y) * speed));
}

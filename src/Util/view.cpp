#include "Util/view.hpp"

void moveViewToPoint(sf::View& view, float x, float y, float speed)
{
    view.setCenter(view.getCenter().x + (x - view.getCenter().x) * speed,
                   view.getCenter().y + (y - view.getCenter().y) * speed);
}

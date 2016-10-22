#include "Util/view.hpp"

namespace util {

void moveViewTowardsPoint(sf::View &view, sf::Vector2f point, float speed)
{
    view.setCenter((int)(view.getCenter().x + (point.x - view.getCenter().x) * speed),
                   (int)(view.getCenter().y + (point.y - view.getCenter().y) * speed));
}

void mapViewerUpdate(sf::View & view, float x, float y)
{
	view.move(x, y);
}
	}

#include "Util/view.hpp"

namespace util {

void moveViewTowardsPoint(sf::View &view, sf::Vector2f point, float speed)
{
    view.setCenter((int)(view.getCenter().x + (point.x - view.getCenter().x) * speed),
                   (int)(view.getCenter().y + (point.y - view.getCenter().y) * speed));
}

void gameViewerMove(sf::View & view, sf::Vector2f direction, float speed)
{
	view.move(direction.x * speed, direction.y*speed);
}
	}

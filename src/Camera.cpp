#include "Camera.hpp"

#include "graphics.hpp"

Camera::Camera()
{
    targetPoint = sf::Vector2f(0,0);

    view = graphics::window.getDefaultView();
    view.setCenter(targetPoint);
    smooth=2;
}

void Camera::cameraMode()
{
    graphics::window.setView(view);
}

void Camera::hudMode()
{
    graphics::window.setView(graphics::window.getDefaultView());
}

void Camera::setTarget(sf::Vector2f new_target)
{
    targetPoint = new_target;
}

void Camera::setTarget(int x_target, int y_target)
{
    targetPoint = sf::Vector2f(x_target, y_target);
}

void Camera::moveTarget(sf::Vector2f offset)
{
    targetPoint+=offset;
}

void Camera::moveTarget(int x_offset, int y_offset)
{
    targetPoint+=sf::Vector2f(x_offset, y_offset);
}

sf::Vector2f Camera::getTarget() const
{
    return targetPoint;
}

sf::View Camera::getView() const
{
    return view;
}

void Camera::setSmooth(int new_smooth)
{
    smooth = new_smooth;
}

void Camera::update()
{
    view.setCenter(view.getCenter().x+(targetPoint.x-view.getCenter().x)/smooth,
                   view.getCenter().y+(targetPoint.y-view.getCenter().y)/smooth);
}

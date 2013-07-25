#include "Core/Camera.hpp"

Camera::Camera(sf::Vector2f size)
{
    m_view.setSize(size);
    m_targetPoint = sf::Vector2f(0,0);
    m_view.setCenter(m_targetPoint);
    m_speed=2;
}

void Camera::apply(sf::RenderTarget &renderTarget)
{
    renderTarget.setView(m_view);
}

void Camera::setTarget(const sf::Vector2f& point)
{
    m_targetPoint = point;
}

void Camera::moveTarget(const sf::Vector2f &offset)
{
    m_targetPoint += offset;
}

sf::Vector2f Camera::getTarget() const
{
    return m_targetPoint;
}

sf::View Camera::getView() const
{
    return m_view;
}

void Camera::setSpeed(float speed)
{
    m_speed = speed;
}

void Camera::update()
{
    m_view.setCenter(m_view.getCenter().x+(m_targetPoint.x-m_view.getCenter().x)/m_speed,
                   m_view.getCenter().y+(m_targetPoint.y-m_view.getCenter().y)/m_speed);
}

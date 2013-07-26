#include "Util/Camera.hpp"
#include "Util/math.hpp"

Camera::Camera(const sf::Vector2f& size, const sf::Vector2f& targetPoint) :
    m_targetPoint(targetPoint),
    m_view(targetPoint, size),
    m_speed(1.0f)
{
}

void Camera::apply(sf::RenderTarget &renderTarget)
{
    renderTarget.setView(m_view);
}

void Camera::setSize(const sf::Vector2f &size)
{
    m_view.setSize(size);
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
    math::clamp(speed, 0.0f, 1.0f);
    m_speed = speed;
}

void Camera::update()
{
    m_view.setCenter(m_view.getCenter().x + (m_targetPoint.x - m_view.getCenter().x) * m_speed,
                     m_view.getCenter().y + (m_targetPoint.y - m_view.getCenter().y) * m_speed);
}
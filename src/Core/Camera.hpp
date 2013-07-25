#ifndef CORE_CAMERA_HPP
#define CORE_CAMERA_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief A camera that follows a target point with a certain speed
 */
class Camera
{
public:
    /**
     * @brief Construct a camera with given size
     * @param size The view area
     */
    Camera(sf::Vector2f size);

    /**
     * @brief Apply the camera to a render target
     * @param renderTarget The render target (e.g. an sf::RenderWindow)
     */
    void apply(sf::RenderTarget& renderTarget);

    /**
     * @brief Set the target the camera should follow
     * @param point The point the camera should follow
     */
    void setTarget(const sf::Vector2f& point);

    /**
     * @brief Move the target point the camera should follow by an offset
     * @param offset Offset to move the point by
     */
    void moveTarget(const sf::Vector2f& offset);

    /**
     * @brief Get the target point the camera is following
     * @return The target point
     */
    sf::Vector2f getTarget() const;

    /**
     * @brief Return the underlying sf::View
     * @return The underlying sf::View
     */
    sf::View getView() const;

    /**
     * @brief Set the speed the camera should follow the target at
     * @param speed The speed the camera should follow the target at
     */
    void setSpeed(float speed);

    /**
     * @brief Update the position of the camera
     *
     * The camera moves in the direction of the target at the given speed
     */
    void update();

private:
    sf::Vector2f m_targetPoint;
    sf::View m_view;
    float m_speed;
};

#endif // CORE_CAMERA_HPP

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>

class Camera
{
public:
    Camera();

    void cameraMode();
    void hudMode();

    void setTarget(sf::Vector2f new_target);
    void setTarget(int x_target, int y_target);
    void moveTarget(sf::Vector2f offset);
    void moveTarget(int x_offset, int y_offset);
    sf::Vector2f getTarget() const;

    sf::View getView() const;

    void update();

private:

    sf::Vector2f targetPoint;
    sf::View view;
    float smooth;

};

#endif //!CAMERA_HPP

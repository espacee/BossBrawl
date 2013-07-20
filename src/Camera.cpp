#include "Camera.hpp"
#include "config.hpp"

#include <iostream>

Camera::Camera()
{

    view.reset(sf::FloatRect(0,0 , config::windowWidth, config::windowHeight));
    view.setViewport(sf::FloatRect(0,0, 1.0f,1.0f));

    EditorHUD.reset(sf::FloatRect(0,0 , config::windowWidth, config::windowHeight));
    EditorHUD.setViewport(sf::FloatRect(0,0, 1.0f,1.0f));

}


void Camera::GameCamera()
{


}

void Camera::EditorCamera()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        view.move(0, -10);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        view.move(10, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        view.move(0, 10);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        view.move(-10, 0);
}

void Camera::ZoomIn()
{
    view.zoom(0.80);

}

void Camera::ZoomOut()
{
    view.zoom(1.20);
}

void Camera::SetView(int i)
{
    if (i == 1)
        graphics::window.setView(view);
    else if (i == 2)
        graphics::window.setView(EditorHUD);
}



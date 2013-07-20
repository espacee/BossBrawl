#include "Camera.hpp"
#include "config.hpp"


Camera::Camera(void)
{

    view.reset(sf::FloatRect(0,0 , config::windowWidth, config::windowHeight));
    view.setViewport(sf::FloatRect(0,0, 1.0f,1.0f));


}


void Camera::GameCamera()
{


}

void Camera::EditorCamera()
{


}

void Camera::ZoomIn(void)
{
    view.zoom(0.80);    
}

void Camera::ZoomOut(void)
{
    view.zoom(1.20);
}



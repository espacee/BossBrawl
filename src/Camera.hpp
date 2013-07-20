#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "graphics.hpp"

class Camera
{
public:
    Camera();

    void GameCamera();
    void EditorCamera();
    void ZoomIn();
    void ZoomOut();
    void SetView(int i);
   
    sf::View view;
    sf::View EditorHUD;
};

#endif //!CAMERA_HPP
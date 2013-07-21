#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "graphics.hpp"

class Camera
{
public:
    Camera();

    void gameCamera();
    void editorCamera();
    void zoomIn();
    void zoomOut();
    void setView(int i);

    sf::View view;
    sf::View EditorHUD;
};

#endif //!CAMERA_HPP

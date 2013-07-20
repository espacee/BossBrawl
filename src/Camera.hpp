#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "graphics.hpp"

class Camera
{
public:
    Camera();

    void GameCamera();
    void EditorCamera();
    void ZoomIn(void);
    void ZoomOut(void);

private:
    sf::View view;
};

#endif //!CAMERA_HPP
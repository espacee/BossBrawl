#ifndef SFMLWIDGET_H
#define SFMLWIDGET_H

#include <SFML/Graphics.hpp>
#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QKeyEvent>
#include <QMouseEvent>
#include "Map/TileMap.hpp"

#include <QDebug>

class SFMLWidget  : public QWidget, public sf::RenderWindow
{
    Q_OBJECT
public:
    SFMLWidget(QWidget* Parent, const QPoint& Position, const QSize& Size, TileMap* mapP, sf::View* cameraP);
    ~SFMLWidget();

    void processEvents();

    void draw(sf::Vector2i mouseCoord);
    void erase(sf::Vector2i mouseCoord);

    void cameraMovementWithMouse(QMouseEvent *event);

public slots:
    void setTool(int newTool);
    void setCurrentTile(int new_id);
    void setCurrentLayer(int newLayer);

private:

    TileMap* map;
    sf::View* camera;
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    QPaintEngine* paintEngine() const;
    void showEvent(QShowEvent*);
    void paintEvent(QPaintEvent*);

    bool initialized, leftButtonDown, rightButtonDown;
    int tool;
    int layer;
    int id;
    int cx, cy;
};

#endif // SFMLWIDGET_H
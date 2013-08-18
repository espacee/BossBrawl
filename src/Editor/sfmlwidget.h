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
public:
    SFMLWidget(QWidget* Parent, const QPoint& Position, const QSize& Size, TileMap* mapP, sf::View* cameraP);
    ~SFMLWidget();

    void setTool(int newTool);
    void setCurrentTile(int new_id);
    void processEvents();

    void draw(sf::Vector2i mouseCoord);
    void erase(sf::Vector2i mouseCoord);

    TileMap* map;
    sf::View* camera;

private:

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    QPaintEngine* paintEngine() const;
    void showEvent(QShowEvent*);
    void paintEvent(QPaintEvent*);

    bool initialized, leftButtonDown, rightButtonDown;
    int tool;
    int id;
};

#endif // SFMLWIDGET_H

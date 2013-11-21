#ifndef MAPWIDGET_HPP
#define MAPWIDGET_HPP

#include <SFML/Graphics.hpp>
#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include "Map/TileMap.hpp"
#include "tools.hpp"

#include <QDebug>

class MapWidget  : public QWidget, public sf::RenderWindow
{
    Q_OBJECT
public:
    MapWidget(QWidget* parent_, const QPoint& position, const QSize& size, sf::View* cameraP);
    ~MapWidget();

    void processEvents();

    void putTile(sf::Vector2i mouseCoord);
    void eraseTile(sf::Vector2i mouseCoord);
    void putEntity(sf::Vector2i mouseCoord, std::string entity);
    void eraseEntity(sf::Vector2i mouseCoord);

public slots:
    void setTool(Tool newTool);
    void setCurrentTile(int new_id);
    void setCurrentLayer(int newLayer);

private:
    sf::View* camera;
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void wheelEvent(QWheelEvent *e);

    QPaintEngine* paintEngine() const;
    void showEvent(QShowEvent*);
    void paintEvent(QPaintEvent*);

    bool initialized, leftButtonDown, rightButtonDown, middleButtonDown, ctrlKeyDown, spaceKeyDown;
    Tool tool;
    int layer;
    int id;
    float x1, x2, y1, y2, dx, dy;
};

#endif // MAPWIDGET_HPP

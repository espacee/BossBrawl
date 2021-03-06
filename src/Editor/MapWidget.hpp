#ifndef MAPWIDGET_HPP
#define MAPWIDGET_HPP

#include <SFML/Graphics.hpp>
#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include "tools.hpp"

#include <QDebug>

class MapWidget  : public QWidget, public sf::RenderWindow
{
    Q_OBJECT
public:
    MapWidget(QWidget *parent_, const QPoint &position, const QSize &size);
    ~MapWidget();

    void processEvents();

    void putTile(sf::Vector2i mouseCoord);
    void eraseTile(sf::Vector2i mouseCoord);
    void putEntity(sf::Vector2i mouseCoord, std::string entity);
    void eraseEntity(sf::Vector2i mouseCoord);
    void render();
    void resetCamera();
    void toggleGrid();

public slots:
    void setTool(Tool newTool);
    void setCurrentTile(int new_id);
    void setCurrentLayer(int newLayer);

private:
    sf::View camera;
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void wheelEvent(QWheelEvent *e);

    QPaintEngine *paintEngine() const;
    void showEvent(QShowEvent *);
    void paintEvent(QPaintEvent *);

    float clear_red, clear_green, clear_blue;
    bool a, b, c;
    bool m_gridEnabled;
    bool initialized, leftButtonDown, rightButtonDown, middleButtonDown, ctrlKeyDown, spaceKeyDown;
    Tool m_tool;
    int layer;
    int id;
    float x1, x2, y1, y2, dx, dy;
};

extern MapWidget *mapWidget;

#endif // MAPWIDGET_HPP

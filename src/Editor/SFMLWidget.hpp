#ifndef SFMLWIDGET_HPP
#define SFMLWIDGET_HPP

#include <SFML/Graphics.hpp>
#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include "Map/TileMap.hpp"
#include "Entities/EntityContainer.hpp"

#include <QDebug>

class SFMLWidget  : public QWidget, public sf::RenderWindow
{
    Q_OBJECT
public:
    SFMLWidget(QWidget* Parent, const QPoint& Position, const QSize& Size, TileMap& map, sf::View* cameraP, EntityContainer& cont);
    ~SFMLWidget();

    void processEvents();

    void putTile(sf::Vector2i mouseCoord);
    void eraseTile(sf::Vector2i mouseCoord);
    void putEntity(sf::Vector2i mouseCoord, std::string entity);
    void eraseEntity(sf::Vector2i mouseCoord);

public slots:
    void setTool(int newTool);
    void setCurrentTile(int new_id);
    void setCurrentLayer(int newLayer);

private:

    TileMap& m_map;
    EntityContainer& m_cont;
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
    int tool, saveTool;
    int layer;
    int id;
    float x1, x2, y1, y2, dx, dy;
};

#endif // SFMLWIDGET_HPP

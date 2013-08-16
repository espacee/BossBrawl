#ifndef SFMLWIDGET_H
#define SFMLWIDGET_H

#include <SFML/Graphics.hpp>
#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include "Map/TileMap.hpp"

class SFMLWidget  : public QWidget, public sf::RenderWindow
{
public:
    SFMLWidget(QWidget* Parent, const QPoint& Position, const QSize& Size);
    ~SFMLWidget();

    void keyPressEvent(QKeyEvent *event);

    TileMap* map;
    sf::View* view;


private:


    QPaintEngine* paintEngine() const;

    void showEvent(QShowEvent*);

    void paintEvent(QPaintEvent*);

   bool initialized;

};

#endif // SFMLWIDGET_H

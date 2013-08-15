#ifndef SFMLWIDGET_H
#define SFMLWIDGET_H

#include <SFML/Graphics.hpp>
#include <QWidget>
#include <QTimer>

class SFMLWidget  : public QWidget, public sf::RenderWindow
{
public:
    SFMLWidget(QWidget* Parent, const QPoint& Position, const QSize& Size);
    ~SFMLWidget();

private:

    QPaintEngine* paintEngine() const;

    void showEvent(QShowEvent*);

    void paintEvent(QPaintEvent*);

   bool initialized;

};

#endif // SFMLWIDGET_H

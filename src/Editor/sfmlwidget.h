#ifndef SFMLWIDGET_H
#define SFMLWIDGET_H

#include <SFML/Graphics.hpp>
#include <QWidget>
#include <QTimer>

class SFMLWidget  : public QWidget, public sf::RenderWindow
{
public:
    SFMLWidget(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 0);
    ~SFMLWidget();

private:

    void OnInit();

    void OnUpdate();

    QPaintEngine* paintEngine() const;

    void showEvent(QShowEvent*);

    void paintEvent(QPaintEvent*);

   QTimer myTimer;
   int i,j,k;
   bool a,b,c;
   bool initialized;

};

#endif // SFMLWIDGET_H

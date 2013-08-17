#ifndef TILEWIDGET_H
#define TILEWIDGET_H

#include <QScrollArea>
#include <QScrollBar>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class TileWidget : public QScrollArea
{
    Q_OBJECT
public:
    TileWidget(QWidget *parent = 0);
    void select(int x, int y);
    int round40(int nb);
    
signals:
    void selected(int);
    void selected(QPixmap);
    
public slots:

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent);
    void showEvent(QShowEvent);

private:

    QWidget* container;
    QPixmap tileSetPixmap;
    QLabel* tileSetLabel;

    QLabel* cursor;

    int id;
    bool leftButtonDown;
};

#endif // TILEWIDGET_H

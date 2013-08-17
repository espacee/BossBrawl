#ifndef TILEWIDGET_H
#define TILEWIDGET_H

#include <QScrollArea>
#include <QScrollBar>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <math.h>

class TileWidget : public QScrollArea
{
    Q_OBJECT
public:
    TileWidget(QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent);
    void mouseMoveEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent);
    void showEvent(QShowEvent);

private:

    QWidget* container;
    QPixmap tileSetPixmap;
    QLabel* tileSetLabel;

    QLabel* cursor;
};

#endif // TILEWIDGET_H

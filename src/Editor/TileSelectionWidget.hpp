#ifndef TILESELECTIONWIDGET_HPP
#define TILESELECTIONWIDGET_HPP

#include <QScrollArea>
#include <QScrollBar>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class TileSelectionWidget : public QScrollArea
{
    Q_OBJECT
public:
    TileSelectionWidget(QWidget *parent = 0);
    void select(int xpos, int ypos);
    int round40(int nb);

signals:
    void selected(int);
    void selected(QPixmap);

public slots:

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent* e);
    void showEvent(QShowEvent*);

private:

    QWidget* container;
    QPixmap tileSetPixmap;
    QLabel* tileSetLabel;

    QLabel* cursor;

    int id;
    bool leftButtonDown;
};

#endif // TILESELECTIONWIDGET_HPP

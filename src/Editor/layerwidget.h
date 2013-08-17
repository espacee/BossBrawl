#ifndef LAYERWIDGET_H
#define LAYERWIDGET_H

#include <QScrollArea>
#include <QScrollBar>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class LayerWidget : public QScrollArea
{
    Q_OBJECT
public:
    LayerWidget(QWidget *parent = 0);

signals:


public slots:

protected:
    void mousePressEvent(QMouseEvent);
    void mouseReleaseEvent(QMouseEvent);
    void mouseMoveEvent(QMouseEvent);
    void keyPressEvent(QKeyEvent);
    void showEvent(QShowEvent);

private:



};

#endif // LAYERWIDGET_H

#ifndef LAYERWIDGET_H
#define LAYERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QResizeEvent>

#include "Editor/layersettings.h"
#include "Map/TileMap.hpp"

class LayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LayerWidget(QString new_name, QWidget *parent, TileMap* mapP);
    void setIndex(int i);
    void setCurrent();
    void unsetCurrent();


signals:
    void selected(int);

public slots:
    void rename(QString new_name);
    void changeWidth(int width);
    void changeHeigth(int height);
    void changeX(int x);
    void changeY(int y);
    void changeDepthIndex(double depthIndex);
    void changeGridColor(QColor color);
    void clearLayer();
    void activateDialog();


protected:
    void mousePressEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);

private:
    TileMap* map;

    QLabel* title;
    QString name;
    QPushButton* propertiesButton;
    LayerSettings* dialog;

    int index;
};

#endif // LAYERWIDGET_H

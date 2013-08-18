#ifndef LAYERTAB_H
#define LAYERTAB_H

#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QResizeEvent>
#include <QVector>
#include <QDebug>

#include "Map/TileMap.hpp"
#include "Editor/layerwidget.h"

class LayerTab : public QWidget
{
    Q_OBJECT
public:
    LayerTab(QWidget *parent, TileMap* mapP);
    
    void addLayer();
    void popLayer();
    void reorder();

signals:
    
public slots:

    void addLayerButtonClicked();
    void removeLayerButtonClicked();
    void selectLayer(int layer);

private:
    TileMap* map;

    void resizeEvent(QResizeEvent *e);
    void mousePressEvent(QMouseEvent *e);

    QScrollArea* layerScrollArea;
    QPushButton* addLayerButton;
    QPushButton* removeLayerButton;

    QWidget* pan;

    QVector<LayerWidget*> layers;
    int nbLayers, currentLayer, layerID;
    int layerWidgetHeigth, offset;

};

#endif // LAYERTAB_H

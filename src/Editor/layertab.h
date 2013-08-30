#ifndef LAYERTAB_H
#define LAYERTAB_H

#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QResizeEvent>
#include <QVector>
#include <QDebug>
#include <QLineEdit>
#include <QRadioButton>
#include <QLabel>

#include "Map/TileMap.hpp"
#include "Editor/layerwidget.h"

class LayerTab : public QWidget
{
    Q_OBJECT
public:
    LayerTab(QWidget *parent, TileMap* mapP);

    void reorder();
    void toggleVisible();
    void updateGrid();
    void updateVisible();

signals:
    void layerSelected(int);

public slots:
    void addLayer();
    int addLayerWidget();
    void loadLayersFromMap();
    void removeLayer();
    void moveBg();
    void moveFg();
    void selectLayer(int layer);

private:
    TileMap* map;

    void resizeEvent(QResizeEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent* e);

    QScrollArea* layerScrollArea;
    QPushButton* addLayerButton;
    QPushButton* removeLayerButton;
    QPushButton* moveBgButton;
    QPushButton* moveFgButton;

    QWidget* pan;

    QVector<LayerWidget*> layers;
    int currentLayer, layerID;
    int layerWidgetHeigth, offset;
    bool currentGridOnly, currentVisibleOnly;

};

#endif // LAYERTAB_H

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
    LayerTab(QWidget *parent, TileMap& m_map);
    void toggleVisible();

signals:
    void layerSelected(int);

public slots:
    void addLayer();
    void addLayerWidget();
    void loadLayersFromMap();
    void removeLayer();
    void moveBg();
    void moveFg();
    void selectLayer(int layer);
    void clearLayers();

private:
    void reorder();
    void updateVisible();

    void resizeEvent(QResizeEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent* e);

    TileMap& m_map;
    int currentLayer, layerID;
    int layerWidgetHeigth, offset;
    bool currentGridOnly, currentVisibleOnly;

    QVector<LayerWidget*> layerWidgets;

    QScrollArea* layerScrollArea;
    QPushButton* addLayerButton;
    QPushButton* removeLayerButton;
    QPushButton* moveBgButton;
    QPushButton* moveFgButton;
    QWidget* pan;
};

#endif // LAYERTAB_H

#ifndef LAYERTABWIDGET_HPP
#define LAYERTABWIDGET_HPP

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
#include "LayerItemWidget.hpp"

class LayerTabWidget : public QWidget
{
    Q_OBJECT
public:
    LayerTabWidget(QWidget *parent, TileMap& m_map);
    void toggleVisible();

signals:
    void layerSelected(int);

public slots:
    void reset();
    void addLayer();
    void addLayerWidget();
    void loadLayersFromMap();
    void removeLayer();
    void moveBg();
    void moveFg();
    void selectLayer(int layer);

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

    QVector<LayerItemWidget*> layerWidgets;

    QScrollArea* layerScrollArea;
    QPushButton* addLayerButton;
    QPushButton* removeLayerButton;
    QPushButton* moveBgButton;
    QPushButton* moveFgButton;
    QWidget* pan;
};

#endif // LAYERTABWIDGET_HPP

#ifndef LAYERTAB_H
#define LAYERTAB_H

#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QResizeEvent>
#include <QVector>

#include "Map/TileMap.hpp"
#include "Editor/layerwidget.h"

class LayerTab : public QWidget
{
    Q_OBJECT
public:
    LayerTab(QWidget *parent, TileMap* mapP);
    
    void addLayer();
    void popLayer();

signals:
    
public slots:

    void addLayerButtonClicked();
    void removeLayerButtonClicked();

private:
    TileMap* map;

    void resizeEvent(QResizeEvent *e);
    void mousePressEvent(QMouseEvent *e);

    QScrollArea* layerScrollArea;
    QPushButton* addLayerButton;
    QPushButton* removeLayerButton;

    QWidget* pan;

    std::vector<QPushButton*> buttons;

};

#endif // LAYERTAB_H

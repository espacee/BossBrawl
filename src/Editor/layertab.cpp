#include "Editor/layertab.h"

LayerTab::LayerTab(QWidget *parent, TileMap* mapP)
{
    map = mapP;
    setParent(parent);
    resize(parent->size());

    addLayerButton = new QPushButton("+",this);
    connect(addLayerButton, SIGNAL(clicked()), this, SLOT(addLayerButtonClicked()));

    removeLayerButton = new QPushButton("-",this);
    connect(removeLayerButton, SIGNAL(clicked()), this, SLOT(removeLayerButtonClicked()));

    layerScrollArea = new QScrollArea(this);
    layerScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    layerScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    pan = new QWidget(this);
    layerScrollArea->setWidget(pan);
    pan->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
    pan->resize(50,800);
}

void LayerTab::addLayer()
{


}

void LayerTab::popLayer()
{

}

void LayerTab::resizeEvent(QResizeEvent *e)
{
    e->ignore();
    addLayerButton->setGeometry(width()-80,height()-40, 40,40);
    removeLayerButton->setGeometry(width()-40,height()-40, 40,40);
    layerScrollArea->move(0,0); layerScrollArea->resize(width(), height()-40);

    pan->resize(layerScrollArea->width()-layerScrollArea->verticalScrollBar()->width(),pan->height());
}

void LayerTab::mousePressEvent(QMouseEvent *e)
{

}

void LayerTab::addLayerButtonClicked()
{
    addLayer();
}

void LayerTab::removeLayerButtonClicked()
{

}

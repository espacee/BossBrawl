#include "Editor/layertab.h"

LayerTab::LayerTab(QWidget *parent, TileMap* mapP)
{
    map = mapP;
    setParent(parent);

    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(45,40,40));
    setPalette(pal);

    addLayerButton = new QPushButton("+",this);
    connect(addLayerButton, SIGNAL(clicked()), this, SLOT(addLayer()));
    addLayerButton->setObjectName("button");

    removeLayerButton = new QPushButton("-",this);
    connect(removeLayerButton, SIGNAL(clicked()), this, SLOT(removeLayer()));
    removeLayerButton->setObjectName("button");

    moveBgButton = new QPushButton("^", this);
    connect(moveBgButton,SIGNAL(clicked()),this,SLOT(moveBg()));
    moveBgButton->setObjectName("button");

    moveFgButton = new QPushButton("v", this);
    connect(moveFgButton,SIGNAL(clicked()),this,SLOT(moveFg()));
    moveFgButton->setObjectName("button");

    layerScrollArea = new QScrollArea(this);
    layerScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    layerScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    layerScrollArea->setAutoFillBackground(true);
    pal.setColor(QPalette::Background, QColor(157,150,150));
    layerScrollArea->setPalette(pal);

    pan = new QWidget(this);
    layerScrollArea->setWidget(pan);
    pan->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
    pan->setAutoFillBackground(true);
    pal.setColor(QPalette::Background, QColor(157,150,150));
    pan->setPalette(pal);

    currentLayer = 0;
    layerWidgetHeigth = 50;
    offset = 1;
    layerID=0;

    addLayerButton->resize(40,40);
    removeLayerButton->resize(addLayerButton->size());
    moveBgButton->resize(addLayerButton->size());
    moveFgButton->resize(addLayerButton->size());

    removeLayerButton->move(width()-44, height()-42);
    addLayerButton->move(removeLayerButton->x()-44,height()-42);
    moveBgButton->move(addLayerButton->x()-44,height()-42);
    moveFgButton->move(moveBgButton->x()-44,height()-42);

    layerScrollArea->move(4,4); layerScrollArea->resize(width()-8, height()- 48);

    pan->setFixedWidth(layerScrollArea->width()-layerScrollArea->verticalScrollBar()->width()-2);
}

void LayerTab::addLayer()
{
    int newLayer;
    if(layers.size()==0)
    {
        newLayer=0;
        layers.push_back(new LayerWidget("Layer "+QString::number(layerID),pan, map));
    }
    else
    {
        newLayer=currentLayer+1;
        layers.insert(layers.begin()+newLayer,new LayerWidget("Layer "+QString::number(layerID),pan, map));
    }
    map->addLayer(newLayer);
    connect(layers[newLayer],SIGNAL(selected(int)),this,SLOT(selectLayer(int)));

    selectLayer(newLayer);

    reorder();
    layerID++;
}

void LayerTab::removeLayer()
{
    if(layers.size()>1)
    {
        int deletedLayer = currentLayer;

        selectLayer(deletedLayer==layers.size()?deletedLayer-1:deletedLayer);

        delete layers[deletedLayer];
        layers.erase(layers.begin()+deletedLayer);
        map->removeLayer(deletedLayer);

        selectLayer(deletedLayer==layers.size()?deletedLayer-1:deletedLayer);

        reorder();
    }
}

void LayerTab::moveBg()
{
    if(currentLayer>0)
    {
        LayerWidget* temp = layers[currentLayer];
        layers[currentLayer] = layers[currentLayer-1];
        layers[currentLayer-1] = temp;
        map->moveLayerBackground(currentLayer);
        selectLayer(currentLayer-1);

        reorder();
    }
}

void LayerTab::moveFg()
{
    if(currentLayer<layers.size()-1)
    {
        LayerWidget* temp = layers[currentLayer];
        layers[currentLayer] = layers[currentLayer+1];
        layers[currentLayer+1] = temp;
        map->moveLayerForeground(currentLayer);
        selectLayer(currentLayer+1);

        reorder();
    }
}

void LayerTab::reorder()
{
    pan->setFixedHeight(layers.size()*(layerWidgetHeigth+offset));

    for(int i=0;i<layers.size();i++)
    {
        layers[i]->resize(pan->width(),layerWidgetHeigth);
        layers[i]->move(0, i*(layerWidgetHeigth+offset));
        layers[i]->show();
        layers[i]->setIndex(i);
    }
}

void LayerTab::resizeEvent(QResizeEvent *e)
{
    e->ignore();
    addLayerButton->resize(40,40);
    removeLayerButton->resize(addLayerButton->size());
    moveBgButton->resize(addLayerButton->size());
    moveFgButton->resize(addLayerButton->size());

    removeLayerButton->move(width()-44, height()-42);
    addLayerButton->move(removeLayerButton->x()-44,height()-42);
    moveBgButton->move(addLayerButton->x()-44,height()-42);
    moveFgButton->move(moveBgButton->x()-44,height()-42);

    layerScrollArea->move(4,4); layerScrollArea->resize(width()-8, height()- 48);

    pan->setFixedWidth(layerScrollArea->width()-layerScrollArea->verticalScrollBar()->width()-2);
    reorder();
}

void LayerTab::mousePressEvent(QMouseEvent *e)
{
    e->ignore();
}
void LayerTab::keyPressEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Delete)
    {
        removeLayer();
    }
}

void LayerTab::selectLayer(int layer)
{
    for(int i=0;i<layers.size();i++)
    {
        layers[i]->unsetCurrent();
    }

    layers[layer]->setCurrent();
    currentLayer=layer;

    emit layerSelected(currentLayer);
}

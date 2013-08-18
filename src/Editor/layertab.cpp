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

    layerName = new QLineEdit("Insert Layername Here.",this);
    layerName->setGeometry(10, height() -42, 200,40);

    layerHeight = new QLineEdit(this);
    layerHeight->setGeometry(10, height() - 70,40,25);

    layerWidth = new QLineEdit(this);
    layerWidth->setGeometry(10 + layerHeight->size().width()+ 15, height() - 70,45,25);

    layerGrid = new QRadioButton(this);
    layerGrid->setGeometry(layerWidth->pos().x() + layerWidth->size().width() + 15, height() - 70,45,25);

    layerHeighttext = new QLabel("Height:", this);
    layerWidthtext = new QLabel("Width: ", this);
    layerGridtext = new QLabel("Grid: ", this);

    layerHeighttext->setGeometry(10, height() - 95,45,30);
    layerWidthtext->setGeometry(10 + layerHeight->size().width()+ 15, height() - 95,45,30);
    layerGridtext->setGeometry(layerWidth->pos().x() + layerWidth->size().width() + 15, height() - 95,45,30);

    nbLayers = 0;
    currentLayer = 0;
    layerWidgetHeigth = 50;
    offset = 1;
    layerID=0;
}

void LayerTab::addLayer()
{
    int newLayer;
    int layerheight = layerHeight->text().toInt();
    int layerwidth = layerWidth->text().toInt();
    bool layergrid;

    if(layerGrid->isChecked())
        layergrid = true;
    else
        layergrid = false;

    QString layername = layerName->text();

    if(nbLayers==0)
    {
        nbLayers=1;
        layers.push_back(new LayerWidget("" +layername,pan));
        newLayer = 0;
        map->addLayer();
        map->resizeLayer(newLayer, layerwidth, layerheight  );
        map->setLayerGridEnabled(newLayer, layergrid);
    }
    else
    {
        nbLayers++;
        layers.insert(currentLayer+1, new LayerWidget("" +layername,pan));

        newLayer = currentLayer+1;

        map->addLayer();
        map->resizeLayer(newLayer, layerwidth, layerheight  );
        map->setLayerGridEnabled(newLayer, layergrid);

    }
    layerID++;

    selectLayer(newLayer);

    connect(layers[currentLayer],SIGNAL(selected(int)),this,SLOT(selectLayer(int)));

    reorder();
}

void LayerTab::popLayer()
{
    for(int i = 0; i < layers.size(); i ++)
    {
        if(layers[i]->isCurrentSet() == true)
        {
            layers.erase(layers.begin() + currentLayer);
            nbLayers--;
            layerID--;
            reorder();
        }
    }
}

void LayerTab::reorder()
{
    pan->setFixedHeight(nbLayers*(layerWidgetHeigth+offset));

    for(int i=0;i<nbLayers;i++)
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
    addLayerButton->setGeometry(width()-82,height()-42, 40,40);
    removeLayerButton->setGeometry(width()-42,height()-42, 40,40);
    layerScrollArea->move(4,4); layerScrollArea->resize(width()-8, height()- 100);

    pan->setFixedWidth(layerScrollArea->width()-layerScrollArea->verticalScrollBar()->width());
}

void LayerTab::mousePressEvent(QMouseEvent *e)
{
    e->ignore();
}
void LayerTab::keyPressEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Delete)
    {
        for(int i = 0; i < layers.size(); i ++)
        {
            if(layers[i]->isCurrentSet() == true)
            {
                popLayer();
            }
        }

    }


}

void LayerTab::addLayerButtonClicked()
{
    addLayer();
    layerName->clear();
}

void LayerTab::removeLayerButtonClicked()
{
popLayer();

}

void LayerTab::selectLayer(int layer)
{
    if(layer>=0 && layer<nbLayers)
    {
        layers[currentLayer]->unsetCurrent();

        currentLayer = layer;

        layers[currentLayer]->setCurrent();
    }
}

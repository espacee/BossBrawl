#include "LayerListWidget.hpp"
#include "LayerSettingsDialog.hpp"
#include "maps.hpp"

LayerListWidget::LayerListWidget(QWidget *parent_)
{
    setParent(parent_);
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(45, 40, 40));
    setPalette(pal);
    addLayerButton = new QPushButton("+", this);
    connect(addLayerButton, SIGNAL(clicked()), this, SLOT(addLayer()));
    addLayerButton->setObjectName("button");
    removeLayerButton = new QPushButton("-", this);
    connect(removeLayerButton, SIGNAL(clicked()), this, SLOT(removeLayer()));
    removeLayerButton->setObjectName("button");
    moveBgButton = new QPushButton("^", this);
    connect(moveBgButton, SIGNAL(clicked()), this, SLOT(moveBg()));
    moveBgButton->setObjectName("button");
    moveFgButton = new QPushButton("v", this);
    connect(moveFgButton, SIGNAL(clicked()), this, SLOT(moveFg()));
    moveFgButton->setObjectName("button");
    layerScrollArea = new QScrollArea(this);
    layerScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    layerScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    layerScrollArea->setAutoFillBackground(true);
    pal.setColor(QPalette::Background, QColor(157, 150, 150));
    layerScrollArea->setPalette(pal);
    pan = new QWidget(this);
    layerScrollArea->setWidget(pan);
    pan->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pan->setAutoFillBackground(true);
    pal.setColor(QPalette::Background, QColor(157, 150, 150));
    pan->setPalette(pal);
    currentLayer = 0;
    layerWidgetHeigth = 30;
    offset = 1;
    layerID = 0;
    addLayerButton->resize(40, 40);
    removeLayerButton->resize(addLayerButton->size());
    moveBgButton->resize(addLayerButton->size());
    moveFgButton->resize(addLayerButton->size());
    removeLayerButton->move(width() - 44, height() - 42);
    addLayerButton->move(removeLayerButton->x() - 44, height() - 42);
    moveFgButton->move(addLayerButton->x() - 44, height() - 42);
    moveBgButton->move(moveFgButton->x() - 44, height() - 42);
    layerScrollArea->move(4, 4);
    layerScrollArea->resize(width() - 8, height() - 48);
    pan->setFixedWidth(layerScrollArea->width() - layerScrollArea->verticalScrollBar()->width() - 2);
    currentGridOnly = false;
    currentVisibleOnly = false;
}

void LayerListWidget::reset()
{
}

void LayerListWidget::addLayer()
{
    maps::current().addLayer(currentLayer + 1);
    loadLayersFromMap();
}

void LayerListWidget::addLayerWidget()
{
    int newLayer;

    if (layerWidgets.size() == 0)
    {
        newLayer = 0;
        layerWidgets.push_back(new LayerItemWidget(pan));
    }
    else
    {
        newLayer = currentLayer + 1;
        layerWidgets.insert(layerWidgets.begin() + newLayer, new LayerItemWidget(pan));
    }

    connect(layerWidgets[newLayer], SIGNAL(selected(int)), this, SLOT(selectLayer(int)));
    selectLayer(newLayer);
    reorder();
    layerID++;
}

void LayerListWidget::loadLayersFromMap()
{
    for (auto w : layerWidgets)
        delete w;

    layerWidgets.clear();

    for (int i = 0; i < maps::current().size(); ++i)
    {
        addLayerWidget();
    }
}

void LayerListWidget::removeLayer()
{
    if (layerWidgets.size() > 1)
    {
        int deletedLayer = currentLayer;
        selectLayer(deletedLayer == layerWidgets.size() ? deletedLayer - 1 : deletedLayer);
        delete layerWidgets[deletedLayer];
        layerWidgets.erase(layerWidgets.begin() + deletedLayer);
        maps::current().removeLayer(deletedLayer);
        selectLayer(deletedLayer == layerWidgets.size() ? deletedLayer - 1 : deletedLayer);
        reorder();
    }
}
void LayerListWidget::moveBg()
{
    if (currentLayer > 0)
    {
        LayerItemWidget *temp = layerWidgets[currentLayer];
        layerWidgets[currentLayer] = layerWidgets[currentLayer - 1];
        layerWidgets[currentLayer - 1] = temp;
        maps::current().moveLayerBackground(currentLayer);
        selectLayer(currentLayer - 1);
        reorder();
    }
}

void LayerListWidget::moveFg()
{
    if (currentLayer < layerWidgets.size() - 1)
    {
        LayerItemWidget *temp = layerWidgets[currentLayer];
        layerWidgets[currentLayer] = layerWidgets[currentLayer + 1];
        layerWidgets[currentLayer + 1] = temp;
        maps::current().moveLayerForeground(currentLayer);
        selectLayer(currentLayer + 1);
        reorder();
    }
}

void LayerListWidget::reorder()
{
    pan->setFixedHeight(layerWidgets.size() * (layerWidgetHeigth + offset));

    for (int i = 0; i < layerWidgets.size(); i++)
    {
        layerWidgets[i]->resize(pan->width(), layerWidgetHeigth);
        layerWidgets[i]->move(0, i * (layerWidgetHeigth + offset));
        layerWidgets[i]->show();
        layerWidgets[i]->setIndex(i);
    }

    updateVisible();
}

void LayerListWidget::resizeEvent(QResizeEvent *e)
{
    e->ignore();
    addLayerButton->resize(40, 40);
    removeLayerButton->resize(addLayerButton->size());
    moveBgButton->resize(addLayerButton->size());
    moveFgButton->resize(addLayerButton->size());
    removeLayerButton->move(width() - 44, height() - 42);
    addLayerButton->move(removeLayerButton->x() - 44, height() - 42);
    moveFgButton->move(addLayerButton->x() - 44, height() - 42);
    moveBgButton->move(moveFgButton->x() - 44, height() - 42);
    layerScrollArea->move(4, 4);
    layerScrollArea->resize(width() - 8, height() - 48);
    pan->setFixedWidth(layerScrollArea->width() - layerScrollArea->verticalScrollBar()->width() - 2);
    reorder();
}

void LayerListWidget::mousePressEvent(QMouseEvent *e)
{
    e->ignore();
}

void LayerListWidget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Delete)
    {
        removeLayer();
    }
}

void LayerListWidget::selectLayer(int layer)
{
    for (int i = 0; i < layerWidgets.size(); i++)
    {
        layerWidgets[i]->unsetCurrent();
    }

    layerWidgets[layer]->setCurrent();
    currentLayer = layer;
    emit layerSelected(currentLayer);
    updateVisible();
}

void LayerListWidget::toggleVisible()
{
    currentVisibleOnly = !currentVisibleOnly;
    updateVisible();
}

void LayerListWidget::updateVisible()
{
    if (currentVisibleOnly)
    {
        for (int i = 0; i < maps::current().size(); i++)
        {
            maps::current()[i].setVisible(false);
        }

        maps::current()[currentLayer].setVisible(true);
    }
    else
    {
        for (int i = 0; i < maps::current().size(); i++)
        {
            maps::current()[i].setVisible(true);
        }
    }
}

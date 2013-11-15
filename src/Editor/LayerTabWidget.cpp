#include "LayerTabWidget.hpp"
#include "LayerSettingsDialog.hpp"

LayerTabWidget::LayerTabWidget(QWidget *parent_, TileMap &map) :
    m_map(map)
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

void LayerTabWidget::reset()
{

}

void LayerTabWidget::addLayer()
{
    m_map.addLayer(currentLayer + 1);
    loadLayersFromMap();
}

void LayerTabWidget::addLayerWidget()
{
    int newLayer;

    if (layerWidgets.size() == 0)
    {
        newLayer = 0;
        layerWidgets.push_back(new LayerWidget(pan, m_map));
    }
    else
    {
        newLayer = currentLayer + 1;
        layerWidgets.insert(layerWidgets.begin() + newLayer, new LayerWidget(pan, m_map));
    }

    connect(layerWidgets[newLayer], SIGNAL(selected(int)), this, SLOT(selectLayer(int)));

    selectLayer(newLayer);

    reorder();
    layerID++;
}

void LayerTabWidget::loadLayersFromMap()
{
    for (auto w : layerWidgets)
        delete w;

    layerWidgets.clear();

    for (int i = 0; i < m_map.size(); ++i)
    {
        addLayerWidget();
    }
}

void LayerTabWidget::removeLayer()
{
    if (layerWidgets.size() > 1)
    {
        int deletedLayer = currentLayer;

        selectLayer(deletedLayer == layerWidgets.size() ? deletedLayer - 1 : deletedLayer);

        delete layerWidgets[deletedLayer];
        layerWidgets.erase(layerWidgets.begin() + deletedLayer);
        m_map.removeLayer(deletedLayer);

        selectLayer(deletedLayer == layerWidgets.size() ? deletedLayer - 1 : deletedLayer);

        reorder();
    }
}
void LayerTabWidget::moveBg()
{
    if (currentLayer > 0)
    {
        LayerWidget* temp = layerWidgets[currentLayer];
        layerWidgets[currentLayer] = layerWidgets[currentLayer - 1];
        layerWidgets[currentLayer - 1] = temp;
        m_map.moveLayerBackground(currentLayer);
        selectLayer(currentLayer - 1);

        reorder();
    }
}

void LayerTabWidget::moveFg()
{
    if (currentLayer < layerWidgets.size() - 1)
    {
        LayerWidget* temp = layerWidgets[currentLayer];
        layerWidgets[currentLayer] = layerWidgets[currentLayer + 1];
        layerWidgets[currentLayer + 1] = temp;
        m_map.moveLayerForeground(currentLayer);
        selectLayer(currentLayer + 1);

        reorder();
    }
}

void LayerTabWidget::reorder()
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

void LayerTabWidget::resizeEvent(QResizeEvent *e)
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

void LayerTabWidget::mousePressEvent(QMouseEvent *e)
{
    e->ignore();
}

void LayerTabWidget::keyPressEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key_Delete)
    {
        removeLayer();
    }
}

void LayerTabWidget::selectLayer(int layer)
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

void LayerTabWidget::toggleVisible()
{
    currentVisibleOnly = !currentVisibleOnly;
    updateVisible();
}

void LayerTabWidget::updateVisible()
{
    if (currentVisibleOnly)
    {
        for (int i = 0; i < m_map.size(); i++)
        {
            m_map[i].setVisible(false);
        }

        m_map[currentLayer].setVisible(true);
    }
    else
    {
        for (int i = 0; i < m_map.size(); i++)
        {
            m_map[i].setVisible(true);
        }
    }
}

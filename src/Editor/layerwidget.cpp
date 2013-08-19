#include "layerwidget.h"
#include "layersettings.h"



LayerWidget::LayerWidget(QString new_name, QWidget *parent, TileMap *mapP) : QWidget(parent)
{
    map = mapP;
    setObjectName("layer");

    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(200,200,200));
    setPalette(pal);

    name = new_name;
    title = new QLabel(name,this);
    title->move(5,5);
    index=0;

    propertiesButton = new QPushButton(">>",this);
    propertiesButton->setGeometry(width()-20,0,20,height());
    propertiesButton->setObjectName("button");
    connect(propertiesButton, SIGNAL(clicked()), this, SLOT(propertiesButtonClicked()));

}

void LayerWidget::setIndex(int i)
{
    index = i;
}

void LayerWidget::setCurrent()
{
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(150,180,255));
    setPalette(pal);
}

void LayerWidget::unsetCurrent()
{
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(200,200,200));
    setPalette(pal);
}

void LayerWidget::rename(QString new_name)
{
    name = new_name;
    title->setText(name);
}

void LayerWidget::mousePressEvent(QMouseEvent *)
{
    emit selected(index);
}

void LayerWidget::resizeEvent(QResizeEvent *)
{

    propertiesButton->setGeometry(width()-20,0,20,height());
}
void LayerWidget::propertiesButtonClicked()
{
map->fillLayer(0,19);

}

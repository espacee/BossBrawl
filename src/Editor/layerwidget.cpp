#include "layerwidget.h"

LayerWidget::LayerWidget(QString new_name, QWidget *parent) : QWidget(parent)
{

    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(157,150,150));
    setPalette(pal);

    name = new_name;
    title = new QLabel("#"+name,this);
    title->move(5,5);
    index=0;
    currentSet = false;
}

void LayerWidget::setIndex(int i)
{
    index = i;
}

void LayerWidget::setCurrent()
{
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(100,150,220));
    setPalette(pal);
    currentSet = true;
}

void LayerWidget::unsetCurrent()
{
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(200,200,200));
    setPalette(pal);
    currentSet = false;
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
bool LayerWidget::isCurrentSet()
{
    return currentSet;

}

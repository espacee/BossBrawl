#include "layerwidget.h"

LayerWidget::LayerWidget(QWidget *parent)
{
    setParent(parent);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(157,150,150));
    setPalette(pal);



}

void LayerWidget::mousePressEvent(QMouseEvent)
{

}

void LayerWidget::mouseReleaseEvent(QMouseEvent)
{

}
void LayerWidget::mouseMoveEvent(QMouseEvent )
{

}
void LayerWidget::keyPressEvent(QKeyEvent)
{

}
void LayerWidget::showEvent(QShowEvent)
{

}

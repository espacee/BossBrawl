#include "layerwidget.h"

LayerWidget::LayerWidget(QWidget *parent) :
    QWidget(parent)
{

    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(157,150,150));
    setPalette(pal);

    btn = new QPushButton("BUTTON",this);
}


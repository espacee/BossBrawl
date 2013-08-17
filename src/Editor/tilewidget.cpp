#include "tilewidget.h"

TileWidget::TileWidget(QWidget *parent)
{
    setParent(parent);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(157,150,150));
    setPalette(pal);

    container = new QWidget(this);
    container->setStyleSheet("background:transparent;");

    tileSetPixmap.load("res/img/tileset.png");

    tileSetLabel = new QLabel(container);
    tileSetLabel->setStyleSheet("background:white;");
    tileSetLabel->setPixmap(tileSetPixmap);
    tileSetLabel->resize(tileSetPixmap.size());

    cursor = new QLabel(container);
    cursor->setPixmap(QPixmap("res/img/GUI/tileSelector.png"));

    container->resize(tileSetLabel->size()+QSize(80,80));
    tileSetLabel->move(40,40);
    cursor->move(40,40);

    setWidget(container);
}

void TileWidget::mousePressEvent(QMouseEvent *e)
{
    cursor->move(e->pos());
}

void TileWidget::mouseReleaseEvent(QMouseEvent)
{

}

void TileWidget::mouseMoveEvent(QMouseEvent *e)
{
    cursor->move(e->pos());
}

void TileWidget::keyPressEvent(QKeyEvent)
{

}

void TileWidget::showEvent(QShowEvent)
{

}

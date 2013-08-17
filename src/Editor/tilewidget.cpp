#include "Editor/tilewidget.h"

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
    tileSetLabel->setPixmap(tileSetPixmap);
    tileSetLabel->resize(tileSetPixmap.size());

    cursor = new QLabel(container);
    cursor->setPixmap(QPixmap("res/img/GUI/tileSelector.png"));

    container->resize(tileSetLabel->size()+QSize(80,80));
    tileSetLabel->move(40,40);
    cursor->move(40,40);

    setWidget(container);

    select(0,0);
    leftButtonDown = false;
}

void TileWidget::select(int x, int y)
{
    x+=horizontalScrollBar()->value();
    y+=verticalScrollBar()->value();

    if(x<40) x=40;  if(x>=40+tileSetLabel->width()) x=tileSetLabel->width();
    if(y<40) y=40;  if(y>=40+tileSetLabel->height()) y=tileSetLabel->height();

    x=round40(x); y=round40(y);
    cursor->move(x,y);

    id = (y-40)/40 * (tileSetLabel->width()/40) + (x-40)/40 +1;

    emit selected(id);
    emit selected(tileSetPixmap.copy(x-40,y-40,40,40));

}

int TileWidget::round40(int nb)
{
    return ((int)nb/40)*40;
}

void TileWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->buttons() == Qt::LeftButton)
    {
        leftButtonDown=true;
        select(e->x(),e->y());
    }
}

void TileWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->buttons() == Qt::LeftButton)
    {
        leftButtonDown=false;
    }
}

void TileWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(leftButtonDown)
    {
        select(e->x(),e->y());
    }
}

void TileWidget::keyPressEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Escape)
        hide();
}

void TileWidget::showEvent(QShowEvent)
{

}

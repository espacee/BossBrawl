#include "TileSelectionWidget.hpp"

TileSelectionWidget::TileSelectionWidget(QWidget *parent_)
{
    setParent(parent_);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(157, 150, 150));
    setPalette(pal);
    container = new QWidget(this);
    container->setStyleSheet("background:transparent;");
    tileSetPixmap.load("res/img/tileset.png");
    tileSetLabel = new QLabel(container);
    tileSetLabel->setPixmap(tileSetPixmap);
    tileSetLabel->resize(tileSetPixmap.size());
    cursor = new QLabel(container);
    cursor->setPixmap(QPixmap("res/img/GUI/tileSelector.png"));
    container->resize(tileSetLabel->size() + QSize(80, 80));
    tileSetLabel->move(40, 40);
    cursor->move(40, 40);
    setWidget(container);
    select(0, 0);
    leftButtonDown = false;
}

void TileSelectionWidget::select(int xpos, int ypos)
{
    xpos += horizontalScrollBar()->value();
    ypos += verticalScrollBar()->value();

    if (xpos < 40) xpos = 40;

    if (xpos >= 40 + tileSetLabel->width()) xpos = tileSetLabel->width();

    if (ypos < 40) ypos = 40;

    if (ypos >= 40 + tileSetLabel->height()) ypos = tileSetLabel->height();

    xpos = round40(xpos);
    ypos = round40(ypos);
    cursor->move(xpos, ypos);
    id = (ypos - 40) / 40 * (tileSetLabel->width() / 40) + (xpos - 40) / 40 + 1;
    emit selected(id);
    emit selected(tileSetPixmap.copy(xpos - 40, ypos - 40, 40, 40));
}

int TileSelectionWidget::round40(int nb)
{
    return ((int)nb / 40) * 40;
}

void TileSelectionWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        leftButtonDown = true;
        select(e->x(), e->y());
    }
}

void TileSelectionWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        leftButtonDown = false;
    }
}

void TileSelectionWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (leftButtonDown)
    {
        select(e->x(), e->y());
    }
}

void TileSelectionWidget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        hide();
}

void TileSelectionWidget::showEvent(QShowEvent *)
{
}

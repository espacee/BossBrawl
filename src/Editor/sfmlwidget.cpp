#include "Editor/sfmlwidget.h"

SFMLWidget::SFMLWidget(QWidget* Parent, const QPoint& Position, const QSize& Size, TileMap* mapP, sf::View* cameraP)
{
    setParent(Parent);
    initialized = false;
    leftButtonDown = false;
    rightButtonDown = false;

    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);

    map = mapP;
    camera = cameraP;

    move(Position);
    resize(Size);
}

void SFMLWidget::setTool(int newTool)
{
    tool = newTool;
}

void SFMLWidget::setCurrentLayer(int newLayer)
{
    layer = newLayer;
}

void SFMLWidget::setCurrentTile(int new_id)
{
    id = new_id;
}

void SFMLWidget::processEvents()
{
    if(tool==10 && !leftButtonDown)
    {
        dx*=0.9; dy*=0.9;
        camera->move(dx,dy);
    }
}

#ifdef Q_WS_X11
    #include <Qt/qx11info_x11.h>
    #include <X11/Xlib.h>
#endif

void SFMLWidget::showEvent(QShowEvent*)
{
    if (!initialized)
    {
        #ifdef Q_WS_X11
            XFlush(QX11Info::display());
        #endif

        sf::Window::create(reinterpret_cast<sf::WindowHandle>(winId()));
        initialized = true;
    }
}

QPaintEngine* SFMLWidget::paintEngine() const
{
    return 0;
}

void SFMLWidget::paintEvent(QPaintEvent*)
{

}

void SFMLWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        leftButtonDown=true;
    }

    if(e->button() == Qt::RightButton)
    {
        rightButtonDown=true;
    }
    if(e->button() == Qt::MiddleButton)
    {
       middleButtonDown=true;
    }


    x1=x2=e->x();
    y1=y2=e->y();
    dx=dy=0;
    mouseMoveEvent(e);
}

void SFMLWidget::mouseMoveEvent(QMouseEvent *e)
{
    x2=e->x();
    y2=e->y();
    dx = x1-x2;
    dy = y1-y2;
    x1=e->x();
    y1=e->y();

    if(rightButtonDown)
    {
        if(tool==1)
            erase(sf::Vector2i(e->x(),e->y()));
    }

    if(leftButtonDown)
    {
        if(tool==1)
            draw(sf::Vector2i(e->x(),e->y()));

        if(tool==4)
            erase(sf::Vector2i(e->x(),e->y()));
        if(tool==10)
            camera->move(dx,dy);
    }
    if(middleButtonDown)
    {
        camera->move(dx,dy);

    }


}

void SFMLWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        leftButtonDown=false;
    }

    if(e->button() == Qt::RightButton)
    {
        rightButtonDown=false;
    }
    if(e->button() == Qt::MiddleButton)
    {
        middleButtonDown=false;
    }

}

SFMLWidget::~SFMLWidget()
{

}

void SFMLWidget::draw(sf::Vector2i mouseCoord)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;
    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord,*camera);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord -  map->getLayerPosition(layer);

    if(layerRelativeCoord.x>0 && layerRelativeCoord.y>0)
    {
        int x = layerRelativeCoord.x /GRID_SIZE ;
        int y = layerRelativeCoord.y /GRID_SIZE ;

        map->setTile(layer,x,y,id);
    }
}

void SFMLWidget::erase(sf::Vector2i mouseCoord)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;
    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord,*camera);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord -  map->getLayerPosition(layer);

    if(layerRelativeCoord.x>0 && layerRelativeCoord.y>0)
    {
        int x = layerRelativeCoord.x /GRID_SIZE ;
        int y = layerRelativeCoord.y /GRID_SIZE ;

        map->setTile(layer,x,y,0);
    }
}


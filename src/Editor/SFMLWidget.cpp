#include "SFMLWidget.hpp"

SFMLWidget::SFMLWidget(QWidget* Parent, const QPoint& Position, const QSize& Size, TileMap &map, sf::View* cameraP, EntityContainer &cont) :
    m_map(map),
    m_cont(cont)
{
    setParent(Parent);
    initialized = false;
    leftButtonDown = false;
    rightButtonDown = false;
    middleButtonDown = false;
    ctrlKeyDown = false;
    spaceKeyDown = false;

    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);

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
}

void SFMLWidget::showEvent(QShowEvent*)
{
    if (!initialized)
    {
#ifdef BRAWL_X11
        sf::Window::create(winId());
#else
        sf::Window::create(reinterpret_cast<sf::WindowHandle>(winId()));
#endif
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

    if (e->button() == Qt::LeftButton)
    {
        leftButtonDown = true;

        if (tool == 11)
            camera->zoom(0.5);

        if (tool == 5)
            m_map[layer].fill(id);

        if (tool == 8)
            putEntity(sf::Vector2i(e->x(), e->y()), "defaultEnemy");

    }

    if (e->button() == Qt::RightButton)
    {
        rightButtonDown = true;

        if (tool == 11)
            camera->zoom(2);

        if (tool == 8)
            eraseEntity(sf::Vector2i(e->x(), e->y()));
    }

    if (e->button() == Qt::MiddleButton)
    {
        middleButtonDown = true;

    }


    x1 = x2 = e->x();
    y1 = y2 = e->y();
    dx = dy = 0;
    mouseMoveEvent(e);
}

void SFMLWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (rightButtonDown)
    {
        if (tool == 1)
            eraseTile(sf::Vector2i(e->x(), e->y()));
    }

    if (leftButtonDown && !spaceKeyDown)
    {
        if (tool == 1)
            putTile(sf::Vector2i(e->x(), e->y()));

        if (tool == 4)
            eraseTile(sf::Vector2i(e->x(), e->y()));

        if (tool == 10)
        {
            x2 = e->x();
            y2 = e->y();
            dx = x1 - x2;
            dy = y1 - y2;
            x1 = e->x();
            y1 = e->y();
            camera->move(dx, dy);
        }
    }

    if ((middleButtonDown && !leftButtonDown) || (spaceKeyDown && leftButtonDown))
    {
        x2 = e->x();
        y2 = e->y();
        dx = x1 - x2;
        dy = y1 - y2;
        x1 = e->x();
        y1 = e->y();
        camera->move(dx, dy);
    }


}

void SFMLWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        leftButtonDown = false;
    }

    if (e->button() == Qt::RightButton)
    {
        rightButtonDown = false;
    }

    if (e->button() == Qt::MiddleButton)
    {
        middleButtonDown = false;
    }
}
void SFMLWidget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Control)
        ctrlKeyDown = true;

    if (e->key() == Qt::Key_Space)
        spaceKeyDown = true;
}

void SFMLWidget::keyReleaseEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Control)
        ctrlKeyDown = false;

    if (e->key() == Qt::Key_Space)
        spaceKeyDown = false;
}

void SFMLWidget::wheelEvent(QWheelEvent *e)
{
    if (ctrlKeyDown)
    {
        if (e->angleDelta().y() > 0)
            camera->zoom(0.5);
        else if (e->angleDelta().y() < 0)
            camera->zoom(2);
    }
}

SFMLWidget::~SFMLWidget()
{

}

void SFMLWidget::putTile(sf::Vector2i mouseCoord)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;

    sf::View temp = *camera;
    temp.setCenter(temp.getCenter().x * m_map[layer].getDepthIndex() - m_map[layer].getPosition().x,
                   temp.getCenter().y * m_map[layer].getDepthIndex() - m_map[layer].getPosition().y);

    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord, temp);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord;

    if (layerRelativeCoord.x > 0 && layerRelativeCoord.y > 0)
    {
        int xpos = layerRelativeCoord.x / GRID_SIZE ;
        int ypos = layerRelativeCoord.y / GRID_SIZE ;


        if (m_map[layer].tileExists(xpos, ypos))
            m_map[layer](xpos, ypos) = id;

    }
}



void SFMLWidget::eraseTile(sf::Vector2i mouseCoord)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;

    sf::View temp = *camera;
    temp.setCenter(temp.getCenter().x * m_map[layer].getDepthIndex() - m_map[layer].getPosition().x,
                   temp.getCenter().y * m_map[layer].getDepthIndex() - m_map[layer].getPosition().y);

    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord, temp);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord;

    if (layerRelativeCoord.x > 0 && layerRelativeCoord.y > 0)
    {
        int xpos = layerRelativeCoord.x / GRID_SIZE ;
        int ypos = layerRelativeCoord.y / GRID_SIZE ;

        if (m_map[layer].tileExists(xpos, ypos))
            m_map[layer](xpos, ypos) = 0;
    }
}
void SFMLWidget::putEntity(sf::Vector2i mouseCoord, std::string entity)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;

    sf::View temp = *camera;
    temp.setCenter(temp.getCenter().x * m_map[layer].getDepthIndex() - m_map[layer].getPosition().x,
                   temp.getCenter().y * m_map[layer].getDepthIndex() - m_map[layer].getPosition().y);

    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord, temp);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord;

    if (layerRelativeCoord.x > 0 && layerRelativeCoord.y > 0)
    {
        int xpos = layerRelativeCoord.x;
        int ypos = layerRelativeCoord.y;


        if (m_map[layer].tileExists(xpos / 40, ypos / 40))
            m_cont.addEntity(entity, (xpos - (m_cont.defaultEnemy[0]->getSize().x / 2)), (ypos - (m_cont.defaultEnemy[0]->getSize().y / 2)));

    }
}

void SFMLWidget::eraseEntity(sf::Vector2i mouseCoord)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;

    sf::View temp = *camera;
    temp.setCenter(temp.getCenter().x * m_map[layer].getDepthIndex() - m_map[layer].getPosition().x,
                   temp.getCenter().y * m_map[layer].getDepthIndex() - m_map[layer].getPosition().y);

    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord, temp);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord;

    if (layerRelativeCoord.x > 0 && layerRelativeCoord.y > 0)
    {
        int xpos = layerRelativeCoord.x;
        int ypos = layerRelativeCoord.y;


        if (m_map[layer].tileExists(xpos / 40, ypos / 40))
        {
            m_cont.deleteEntity(xpos, ypos);
        }


    }
}

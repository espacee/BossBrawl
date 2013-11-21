#include "MapWidget.hpp"

MapWidget::MapWidget(QWidget* parent_, const QPoint& position, const QSize& size_, TileMap &map, sf::View* cameraP, EntityContainer &cont) :
    QWidget(parent_),
    m_map(map),
    m_cont(cont)
{
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
    move(position);
    resize(size_);
}

void MapWidget::setTool(Tool newTool)
{
    tool = newTool;
}

void MapWidget::setCurrentLayer(int newLayer)
{
    layer = newLayer;
}

void MapWidget::setCurrentTile(int new_id)
{
    id = new_id;
}

void MapWidget::processEvents()
{
}

void MapWidget::showEvent(QShowEvent*)
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

QPaintEngine* MapWidget::paintEngine() const
{
    return 0;
}

void MapWidget::paintEvent(QPaintEvent*)
{
}

void MapWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        leftButtonDown = true;

        if (tool == Tool::Zoom)
            camera->zoom(0.5);

        if (tool == Tool::FillShape)
            m_map[layer].fill(id);

        if (tool == Tool::Entity)
            putEntity(sf::Vector2i(e->x(), e->y()), "defaultEnemy");
    }

    if (e->button() == Qt::RightButton)
    {
        rightButtonDown = true;

        if (tool == Tool::Zoom)
            camera->zoom(2);

        if (tool == Tool::Entity)
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

void MapWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (rightButtonDown)
    {
        if (tool == Tool::Pen)
            eraseTile(sf::Vector2i(e->x(), e->y()));
    }

    if (leftButtonDown && !spaceKeyDown)
    {
        if (tool == Tool::Pen)
            putTile(sf::Vector2i(e->x(), e->y()));

        if (tool == Tool::Eraser)
            eraseTile(sf::Vector2i(e->x(), e->y()));

        if (tool == Tool::Hand)
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

void MapWidget::mouseReleaseEvent(QMouseEvent *e)
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

void MapWidget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Control)
        ctrlKeyDown = true;

    if (e->key() == Qt::Key_Space)
        spaceKeyDown = true;
}

void MapWidget::keyReleaseEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Control)
        ctrlKeyDown = false;

    if (e->key() == Qt::Key_Space)
        spaceKeyDown = false;
}

void MapWidget::wheelEvent(QWheelEvent *e)
{
    if (ctrlKeyDown)
    {
        if (e->angleDelta().y() > 0)
            camera->zoom(0.5);
        else if (e->angleDelta().y() < 0)
            camera->zoom(2);
    }
}

MapWidget::~MapWidget()
{
}

void MapWidget::putTile(sf::Vector2i mouseCoord)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;
    sf::View temp = *camera;
    temp.setCenter(temp.getCenter().x * m_map[layer].getDepthIndex() - m_map[layer].getPosition().x,
                   temp.getCenter().y * m_map[layer].getDepthIndex() - m_map[layer].getPosition().y);
    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord, temp);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord;

    if (layerRelativeCoord.x > 0 && layerRelativeCoord.y > 0)
    {
        int xpos = layerRelativeCoord.x / Layer::TILE_SIZE ;
        int ypos = layerRelativeCoord.y / Layer::TILE_SIZE ;

        if (m_map[layer].tileExists(xpos, ypos))
            m_map[layer](xpos, ypos) = id;
    }
}

void MapWidget::eraseTile(sf::Vector2i mouseCoord)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;
    sf::View temp = *camera;
    temp.setCenter(temp.getCenter().x * m_map[layer].getDepthIndex() - m_map[layer].getPosition().x,
                   temp.getCenter().y * m_map[layer].getDepthIndex() - m_map[layer].getPosition().y);
    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord, temp);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord;

    if (layerRelativeCoord.x > 0 && layerRelativeCoord.y > 0)
    {
        int xpos = layerRelativeCoord.x / Layer::TILE_SIZE ;
        int ypos = layerRelativeCoord.y / Layer::TILE_SIZE ;

        if (m_map[layer].tileExists(xpos, ypos))
            m_map[layer](xpos, ypos) = 0;
    }
}

void MapWidget::putEntity(sf::Vector2i mouseCoord, std::string entity)
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

void MapWidget::eraseEntity(sf::Vector2i mouseCoord)
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

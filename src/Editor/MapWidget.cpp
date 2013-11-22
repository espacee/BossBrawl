#include "MapWidget.hpp"
#include "maps.hpp"

MapWidget::MapWidget(QWidget *parent_, const QPoint &position, const QSize &size_) :
    QWidget(parent_)
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
    move(position);
    resize(size_);
    clear_red = clear_green = clear_blue = 127;
    a = b = c = true;
    camera = sf::View(sf::FloatRect(0, 0, width() - 1, height() - 1));
    camera.setCenter(0, 0);
    m_gridEnabled = false;
}

void MapWidget::setTool(Tool newTool)
{
    m_tool = newTool;
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

void MapWidget::showEvent(QShowEvent *)
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

QPaintEngine *MapWidget::paintEngine() const
{
    return 0;
}

void MapWidget::paintEvent(QPaintEvent *)
{
}

void MapWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        leftButtonDown = true;

        if (m_tool == Tool::Zoom)
            camera.zoom(0.5);

        if (m_tool == Tool::FillShape)
            maps::current()[layer].fill(id);

        if (m_tool == Tool::Entity)
            putEntity(sf::Vector2i(e->x(), e->y()), "defaultEnemy");
    }

    if (e->button() == Qt::RightButton)
    {
        rightButtonDown = true;

        if (m_tool == Tool::Zoom)
            camera.zoom(2);

        if (m_tool == Tool::Entity)
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
        if (m_tool == Tool::Pen)
            eraseTile(sf::Vector2i(e->x(), e->y()));
    }

    if (leftButtonDown && !spaceKeyDown)
    {
        if (m_tool == Tool::Pen)
            putTile(sf::Vector2i(e->x(), e->y()));

        if (m_tool == Tool::Eraser)
            eraseTile(sf::Vector2i(e->x(), e->y()));

        if (m_tool == Tool::Hand)
        {
            x2 = e->x();
            y2 = e->y();
            dx = x1 - x2;
            dy = y1 - y2;
            x1 = e->x();
            y1 = e->y();
            camera.move(dx, dy);
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
        camera.move(dx, dy);
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
            camera.zoom(0.5);
        else if (e->angleDelta().y() < 0)
            camera.zoom(2);
    }
}

MapWidget::~MapWidget()
{
}

void MapWidget::putTile(sf::Vector2i mouseCoord)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;
    sf::View temp = camera;
    temp.setCenter(temp.getCenter().x * maps::current()[layer].getDepthIndex() - maps::current()[layer].getPosition().x,
                   temp.getCenter().y * maps::current()[layer].getDepthIndex() - maps::current()[layer].getPosition().y);
    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord, temp);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord;

    if (layerRelativeCoord.x > 0 && layerRelativeCoord.y > 0)
    {
        int xpos = layerRelativeCoord.x / Layer::TILE_SIZE ;
        int ypos = layerRelativeCoord.y / Layer::TILE_SIZE ;

        if (maps::current()[layer].tileExists(xpos, ypos))
            maps::current()[layer](xpos, ypos) = id;
    }
}

void MapWidget::eraseTile(sf::Vector2i mouseCoord)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;
    sf::View temp = camera;
    temp.setCenter(temp.getCenter().x * maps::current()[layer].getDepthIndex() - maps::current()[layer].getPosition().x,
                   temp.getCenter().y * maps::current()[layer].getDepthIndex() - maps::current()[layer].getPosition().y);
    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord, temp);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord;

    if (layerRelativeCoord.x > 0 && layerRelativeCoord.y > 0)
    {
        int xpos = layerRelativeCoord.x / Layer::TILE_SIZE ;
        int ypos = layerRelativeCoord.y / Layer::TILE_SIZE ;

        if (maps::current()[layer].tileExists(xpos, ypos))
            maps::current()[layer](xpos, ypos) = 0;
    }
}

void MapWidget::putEntity(sf::Vector2i mouseCoord, std::string entity)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;
    sf::View temp = camera;
    temp.setCenter(temp.getCenter().x * maps::current()[layer].getDepthIndex() - maps::current()[layer].getPosition().x,
                   temp.getCenter().y * maps::current()[layer].getDepthIndex() - maps::current()[layer].getPosition().y);
    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord, temp);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord;

    if (layerRelativeCoord.x > 0 && layerRelativeCoord.y > 0)
    {
        int xpos = layerRelativeCoord.x;
        int ypos = layerRelativeCoord.y;

        if (maps::current()[layer].tileExists(xpos / 40, ypos / 40))
            maps::currentEntityContainer().addEntity(entity, (xpos - (maps::currentEntityContainer().defaultEnemy[0]->getSize().x / 2)), (ypos - (maps::currentEntityContainer().defaultEnemy[0]->getSize().y / 2)));
    }
}

void MapWidget::eraseEntity(sf::Vector2i mouseCoord)
{
    sf::Vector2i windowRelativeCoord = mouseCoord;
    sf::View temp = camera;
    temp.setCenter(temp.getCenter().x * maps::current()[layer].getDepthIndex() - maps::current()[layer].getPosition().x,
                   temp.getCenter().y * maps::current()[layer].getDepthIndex() - maps::current()[layer].getPosition().y);
    sf::Vector2f worldRelativeCoord =  mapPixelToCoords(windowRelativeCoord, temp);
    sf::Vector2f layerRelativeCoord = worldRelativeCoord;

    if (layerRelativeCoord.x > 0 && layerRelativeCoord.y > 0)
    {
        int xpos = layerRelativeCoord.x;
        int ypos = layerRelativeCoord.y;

        if (maps::current()[layer].tileExists(xpos / 40, ypos / 40))
        {
            maps::currentEntityContainer().deleteEntity(xpos, ypos);
        }
    }
}

void MapWidget::render()
{
    if (a) clear_red += 0.001;
    else clear_red -= 0.001;

    if (clear_red >= 255 || clear_red <= 0) a = !a;

    if (b) clear_green += 0.015;
    else clear_green -= 0.015;

    if (clear_green >= 255 || clear_green <= 0) b = !b;

    if (c) clear_blue += 0.005;
    else clear_blue -= 0.005;

    if (clear_blue >= 255 || clear_blue <= 0) c = !c;

    processEvents();
    clear(sf::Color(clear_red, clear_green, clear_blue));
    maps::currentEntityContainer().displayEntities(*this);
    setView(camera);
    maps::current().draw(*this, (m_gridEnabled ? layer : - 1));
    display();
}

void MapWidget::resetCamera()
{
    camera = sf::View(sf::FloatRect(0, 0, width() - 1, height() - 1));
    camera.setCenter(0, 0);
}

void MapWidget::toggleGrid()
{
    m_gridEnabled = !m_gridEnabled;
}

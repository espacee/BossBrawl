#include "Editor/sfmlwidget.h"

SFMLWidget::SFMLWidget(QWidget* Parent, const QPoint& Position, const QSize& Size)
{
    setParent(Parent);
    initialized = false;

    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);

    move(Position);
    resize(Size);
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
void SFMLWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Q)
        view->move(20,0);
    if(event->key() == Qt::Key_S)
        view->move(0,-20);
    if(event->key() == Qt::Key_D)
        view->move(-20,0);
    if(event->key() == Qt::Key_Z)
        view->move(0,20);

}
void SFMLWidget::mousePressEvent(QMouseEvent *event)
{
    Qt::MouseButtons mouseButtons = event->buttons();

    if( mouseButtons == Qt::LeftButton )
    {

    }
    else if( mouseButtons == Qt::RightButton)
    {

    }
}

SFMLWidget::~SFMLWidget()
{

}

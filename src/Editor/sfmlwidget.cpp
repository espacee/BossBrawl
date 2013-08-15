#include "sfmlwidget.h"

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

SFMLWidget::~SFMLWidget()
{

}

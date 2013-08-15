#include "sfmlwidget.h"

SFMLWidget::SFMLWidget(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime)
{
    setParent(Parent);
    initialized = false;

    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);

    move(Position);
    resize(Size);

    myTimer.setInterval(FrameTime);
    i=j=k=0;
    a=b=c=1;
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

        OnInit();

        connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
        myTimer.start();

        initialized = true;
    }
}

QPaintEngine* SFMLWidget::paintEngine() const
{
    return 0;
}

void SFMLWidget::paintEvent(QPaintEvent*)
{
    OnUpdate();

    sf::RenderWindow::display();
}

SFMLWidget::~SFMLWidget()
{

}

 void SFMLWidget::OnInit()
{

}

 void SFMLWidget::OnUpdate()
{
     if(a) i++; else i--;
     if(i>=255 || i<=0) a=!a;

     if(b) j+=15; else j-=15;
     if(j>=255 || j<=0) b=!b;

     if(c) k+=5; else k-=5;
     if(k>=255 || k<=0) c=!c;

    sf::RenderWindow::clear(sf::Color(i,j,k));
}

#include "editorWindow.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setGeometry(QApplication::desktop()->availableGeometry());
    setWindowTitle("BossBrawl-Editor");

    menuBarHeight=50;
    globalPadding=5;
    toolBarWidth=40;
    topBarHeight=30;
    rightPanelWidth=200;
    botBarHeight=20;

    toolBar = new QWidget(this);
    toolBar->setGeometry(globalPadding,
                         menuBarHeight,
                         toolBarWidth,
                         height()-menuBarHeight-globalPadding);

    rightPanel = new QWidget(this);
    rightPanel->setGeometry(width()-globalPadding-rightPanelWidth,
                            menuBarHeight,
                            rightPanelWidth,
                            height()-menuBarHeight-botBarHeight-globalPadding);

    topBar = new QWidget(this);
    topBar->setGeometry(globalPadding+toolBarWidth,
                        menuBarHeight,
                        width()-toolBarWidth-rightPanelWidth-globalPadding*2,
                        topBarHeight);

    botBar = new QWidget(this);
    botBar->setGeometry(globalPadding+toolBarWidth,
                        height()-globalPadding-botBarHeight,
                        width()-toolBarWidth-globalPadding*2,
                        botBarHeight);

    centralWidget = new QWidget(this);
    centralWidget->setGeometry(toolBar->x()+toolBar->width(),
                               topBar->y()+topBar->height(),
                               width()-toolBar->x()-toolBar->width()-rightPanelWidth-globalPadding,
                               height()-menuBarHeight-topBarHeight-globalPadding-botBarHeight);

    toolBar->setStyleSheet("background-color:black;");
    rightPanel->setStyleSheet("background-color:blue;");
    topBar->setStyleSheet("background-color:red;");
    botBar->setStyleSheet("background-color:yellow;");
    centralWidget->setStyleSheet("background-color:green;");
}

void Window::showEvent(QShowEvent*)
{
}

Window::~Window()
{
    
}

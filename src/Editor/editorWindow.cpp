#include "editorWindow.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setGeometry(QApplication::desktop()->availableGeometry());
    setWindowTitle("BossBrawl-Editor");

    menuBarHeight=50;
    globalPadding=5;

    toolBarWidth=44;
    toolButtonSize=40;
    toolButtonPadding = 2;
    toolBarTopOffset = 30;
    toolSeparatorSize = 10;

    topBarHeight=30;

    rightPanelWidth=300;

    botBarHeight=20;

    initWindow();
    initToolBar();
    initRightPanel();
    initTopBar();
    initBotBar();
    initCentralWidget();

    setObjectName("window");
    toolBar->setObjectName("toolBar");
    rightPanel->setObjectName("rightPanel");
    topBar->setObjectName("topBar");
    botBar->setObjectName("botBar");
    centralWidget->setObjectName("centralWidget");

    QFile styleSheetFile("res/style/editor-stylesheet.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheetString = QLatin1String(styleSheetFile.readAll());
    setStyleSheet(styleSheetString);
}

Window::~Window()
{
    
}

void Window::initWindow()
{
    windowIcon = new QLabel("Icon",this);
    windowIcon->setGeometry(0,0,menuBarHeight,menuBarHeight);

    closeButton = new QPushButton("x",this);
    closeButton->setGeometry(width()-22,2,20,20);
    connect(closeButton,SIGNAL(clicked()),this,SLOT(quitClicked()));

    minimizeButton = new QPushButton("-",this);
    minimizeButton->setGeometry(closeButton->x()-22,2,20,20);
    connect(minimizeButton,SIGNAL(clicked()),this,SLOT(minimizeClicked()));
}

void Window::initToolBar()
{
    toolBar = new QWidget(this);
    toolBar->setGeometry(globalPadding,
                         menuBarHeight,
                         toolBarWidth,
                         height()-menuBarHeight-globalPadding);

    toolBarTitle = new QLabel("Tools", toolBar);
    toolBarTitle->setGeometry(0,0,toolBarWidth, toolBarTopOffset);

    pointerToolButton = new QPushButton("Pointer", toolBar);
    pointerToolButton->setGeometry(
                toolButtonPadding,
                toolButtonPadding+toolBarTopOffset,
                toolButtonSize,
                toolButtonSize);

    penToolButton = new QPushButton("Pen",toolBar);
    penToolButton->setGeometry(
                toolButtonPadding,
                pointerToolButton->y()+pointerToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);

    randomPenToolButton = new QPushButton("rndPen",toolBar);
    randomPenToolButton->setGeometry(
                toolButtonPadding,
                penToolButton->y()+penToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);

    patternBrushToolButton = new QPushButton("Pattern", toolBar);
    patternBrushToolButton->setGeometry(
                toolButtonPadding,
                randomPenToolButton->y()+randomPenToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);

    eraserToolButton = new QPushButton("Eraser", toolBar);
    eraserToolButton->setGeometry(
                toolButtonPadding,
                patternBrushToolButton->y()+patternBrushToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);

    fillShapeToolButton = new QPushButton("Shape", toolBar);
    fillShapeToolButton->setGeometry(
                toolButtonPadding,
                eraserToolButton->y()+eraserToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);

    selectAreaToolButton = new QPushButton("Select",toolBar);
    selectAreaToolButton->setGeometry(
                toolButtonPadding,
                fillShapeToolButton->y()+fillShapeToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);

    //

    arrowToolButton = new QPushButton("Arrow",toolBar);
    arrowToolButton->setGeometry(
                toolButtonPadding,
                toolSeparatorSize + selectAreaToolButton->y()+selectAreaToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);

    entityToolButton = new QPushButton("Entity",toolBar);
    entityToolButton->setGeometry(
                toolButtonPadding,
                arrowToolButton->y()+arrowToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);

    objectToolButton = new QPushButton("Object", toolBar);
    objectToolButton->setGeometry(
                toolButtonPadding,
                entityToolButton->y()+entityToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);

    //

    handToolButton = new QPushButton("Hand", toolBar);
    handToolButton->setGeometry(
                toolButtonPadding,
                toolSeparatorSize + objectToolButton->y()+objectToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);

    zoomToolButton = new QPushButton("Zoom", toolBar);
    zoomToolButton->setGeometry(
                toolButtonPadding,
                handToolButton->y()+handToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
}

void Window::initTopBar()
{
    topBar = new QWidget(this);
    topBar->setGeometry(globalPadding+toolBarWidth,
                        menuBarHeight,
                        width()-toolBarWidth-rightPanelWidth-globalPadding*2,
                        topBarHeight);
}

void Window::initRightPanel()
{
    rightPanel = new QWidget(this);
    rightPanel->setGeometry(width()-globalPadding-rightPanelWidth,
                            menuBarHeight,
                            rightPanelWidth,
                            height()-menuBarHeight-botBarHeight-globalPadding);
}

void Window::initBotBar()
{
    botBar = new QWidget(this);
    botBar->setGeometry(globalPadding+toolBarWidth,
                        height()-globalPadding-botBarHeight,
                        width()-toolBarWidth-globalPadding*2,
                        botBarHeight);
}

void Window::initCentralWidget()
{
    centralWidget = new QWidget(this);
    centralWidget->setGeometry(toolBar->x()+toolBar->width(),
                               topBar->y()+topBar->height(),
                               width()-toolBar->x()-toolBar->width()-rightPanelWidth-globalPadding,
                               height()-menuBarHeight-topBarHeight-globalPadding-botBarHeight);
}


void Window::quitClicked()
{
    close();
}

void Window::minimizeClicked()
{
    setWindowState(Qt::WindowMinimized);
}

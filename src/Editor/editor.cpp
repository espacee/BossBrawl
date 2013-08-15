#include "editor.h"

Editor::Editor(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setGeometry(QApplication::desktop()->availableGeometry());
    setWindowTitle("Editor");
    setWindowIcon(QIcon("res/img/GUI/windowIcon.png"));

    menuBarHeight=50;
    globalPadding=5;

    toolBarWidth=34;
    toolButtonSize=30;
    toolButtonPadding = 2;
    toolBarTopOffset = 2;
    toolSeparatorSize = 10;

    topBarHeight=30;

    rightPanelWidth=300;

    botBarHeight=30;

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

    frameTime = 16; // 62.5 ms = 16 fps    40 ms = 25 fps    16.6 ms = 60 fps    12.5 ms = 80 fps
    timer.setInterval(frameTime);
    connect(&timer, SIGNAL(timeout()), this, SLOT(onUpdate()));
    timer.start();

    i=j=k=0;
    a=b=c=true;

    onInit();
}

Editor::~Editor()
{
    
}

void Editor::onInit()
{
    map.resizeLayer(0,10,10);
    map.fillLayer(0,1);
}

void Editor::onUpdate()
{
    if(a) i++; else i--;
    if(i>=255 || i<=0) a=!a;

    if(b) j+=15; else j-=15;
    if(j>=255 || j<=0) b=!b;

    if(c) k+=5; else k-=5;
    if(k>=255 || k<=0) c=!c;

    sfmlWidget->clear(sf::Color(i,j,k));

    map.display(*sfmlWidget);

    sfmlWidget->sf::RenderWindow::display();
}

void Editor::initWindow()
{
    windowIcon = new QLabel("",this);
    windowIcon->setPixmap(QPixmap("res/img/GUI/windowIcon.png"));
    windowIcon->setGeometry(0,0,menuBarHeight,menuBarHeight);

    closeButton = new QPushButton(QIcon("res/img/GUI/close.png"),"",this);
    closeButton->setGeometry(width()-32,0,30,20);
    closeButton->setObjectName("closeButton");
    connect(closeButton,SIGNAL(clicked()),this,SLOT(quitClicked()));

    minimizeButton = new QPushButton(QIcon("res/img/GUI/minimize.png"),"",this);
    minimizeButton->setGeometry(closeButton->x()-31,0,30,20);
    minimizeButton->setObjectName("minimizeButton");
    connect(minimizeButton,SIGNAL(clicked()),this,SLOT(minimizeClicked()));
}

void Editor::initToolBar()
{
    toolBar = new QWidget(this);
    toolBar->setGeometry(globalPadding,
                         menuBarHeight,
                         toolBarWidth,
                         height()-menuBarHeight-globalPadding);

    pointerToolButton = new QPushButton(QIcon("res/img/GUI/pointer.png"),"", toolBar);
    pointerToolButton->setGeometry(
                toolButtonPadding,
                toolButtonPadding+toolBarTopOffset,
                toolButtonSize,
                toolButtonSize);
    pointerToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    pointerToolButton->setObjectName("toolButton");

    penToolButton = new QPushButton(QIcon("res/img/GUI/pen.png"),"",toolBar);
    penToolButton->setGeometry(
                toolButtonPadding,
                pointerToolButton->y()+pointerToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    penToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    penToolButton->setObjectName("toolButton");

    randomPenToolButton = new QPushButton(QIcon("res/img/GUI/randomPen.png"),"",toolBar);
    randomPenToolButton->setGeometry(
                toolButtonPadding,
                penToolButton->y()+penToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    randomPenToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    randomPenToolButton->setObjectName("toolButton");

    patternBrushToolButton = new QPushButton(QIcon("res/img/GUI/patternBrush.png"),"", toolBar);
    patternBrushToolButton->setGeometry(
                toolButtonPadding,
                randomPenToolButton->y()+randomPenToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    patternBrushToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    patternBrushToolButton->setObjectName("toolButton");

    eraserToolButton = new QPushButton(QIcon("res/img/GUI/eraser.png"),"", toolBar);
    eraserToolButton->setGeometry(
                toolButtonPadding,
                patternBrushToolButton->y()+patternBrushToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    eraserToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    eraserToolButton->setObjectName("toolButton");

    fillShapeToolButton = new QPushButton(QIcon("res/img/GUI/fillShape.png"),"", toolBar);
    fillShapeToolButton->setGeometry(
                toolButtonPadding,
                eraserToolButton->y()+eraserToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    fillShapeToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    fillShapeToolButton->setObjectName("toolButton");

    selectAreaToolButton = new QPushButton(QIcon("res/img/GUI/selectArea.png"),"",toolBar);
    selectAreaToolButton->setGeometry(
                toolButtonPadding,
                fillShapeToolButton->y()+fillShapeToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    selectAreaToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    selectAreaToolButton->setObjectName("toolButton");

    //

    arrowToolButton = new QPushButton(QIcon("res/img/GUI/arrow.png"),"",toolBar);
    arrowToolButton->setGeometry(
                toolButtonPadding,
                toolSeparatorSize + selectAreaToolButton->y()+selectAreaToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    arrowToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    arrowToolButton->setObjectName("toolButton");

    entityToolButton = new QPushButton(QIcon("res/img/GUI/entity.png"),"",toolBar);
    entityToolButton->setGeometry(
                toolButtonPadding,
                arrowToolButton->y()+arrowToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    entityToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    entityToolButton->setObjectName("toolButton");

    objectToolButton = new QPushButton(QIcon("res/img/GUI/object.png"),"", toolBar);
    objectToolButton->setGeometry(
                toolButtonPadding,
                entityToolButton->y()+entityToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    objectToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    objectToolButton->setObjectName("toolButton");

    //

    handToolButton = new QPushButton(QIcon("res/img/GUI/hand.png"),"", toolBar);
    handToolButton->setGeometry(
                toolButtonPadding,
                toolSeparatorSize + objectToolButton->y()+objectToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    handToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    handToolButton->setObjectName("toolButton");

    zoomToolButton = new QPushButton(QIcon("res/img/GUI/zoom.png"),"", toolBar);
    zoomToolButton->setGeometry(
                toolButtonPadding,
                handToolButton->y()+handToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    zoomToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    zoomToolButton->setObjectName("toolButton");
}

void Editor::initTopBar()
{
    topBar = new QWidget(this);
    topBar->setGeometry(globalPadding+toolBarWidth,
                        menuBarHeight,
                        width()-toolBarWidth-rightPanelWidth-globalPadding*2,
                        topBarHeight);
}

void Editor::initRightPanel()
{
    rightPanel = new QWidget(this);
    rightPanel->setGeometry(width()-globalPadding-rightPanelWidth,
                            menuBarHeight,
                            rightPanelWidth,
                            height()-menuBarHeight-globalPadding);
}

void Editor::initBotBar()
{
    botBar = new QWidget(this);
    botBar->setGeometry(globalPadding+toolBarWidth,
                        height()-globalPadding-botBarHeight,
                        width()-toolBarWidth-rightPanelWidth-globalPadding*2,
                        botBarHeight);
}

void Editor::initCentralWidget()
{
    centralWidget = new QWidget(this);
    centralWidget->setGeometry(toolBar->x()+toolBar->width(),
                               topBar->y()+topBar->height(),
                               width()-toolBar->x()-toolBar->width()-rightPanelWidth-globalPadding,
                               height()-menuBarHeight-topBarHeight-globalPadding-botBarHeight);

    sfmlWidget = new SFMLWidget(centralWidget,QPoint(0,0),centralWidget->size());
}


void Editor::quitClicked()
{
    close();
}

void Editor::minimizeClicked()
{
    setWindowState(Qt::WindowMinimized);
}

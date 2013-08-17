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
    toolBarTopOffset = 44;
    toolSeparatorSize = 10;

    topBarHeight =44;
    topButtonSize = 42;

    rightPanelWidth=300;

    botBarHeight=40;

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

    onInit();

    i=j=k=127;
    a=b=c=true;
    tileWidget->select(0,0);
    penToolButtonClicked();
}

Editor::~Editor()
{
    
}

void Editor::onInit()
{
    camera = sf::View(sf::FloatRect(0, 0, sfmlWidget->width(), sfmlWidget->height()));
    camera.setCenter(0,0);

    map.resizeLayer(0,50,50);
    map.fillLayer(0,0);
    map.setLayerGridEnabled(0,true);

    camera.move(1000,1000);

}

void Editor::onUpdate()
{
    if(a) i+=0.001; else i-=0.001;
    if(i>=255 || i<=0) a=!a;

    if(b) j+=0.015; else j-=0.015;
    if(j>=255 || j<=0) b=!b;

    if(c) k+=0.005; else k-=0.005;
    if(k>=255 || k<=0) c=!c;


    sfmlWidget->clear(sf::Color(i,j,k));

    sfmlWidget->setView(camera);
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
    pointerToolButton->setCheckable(true);

    penToolButton = new QPushButton(QIcon("res/img/GUI/pen.png"),"",toolBar);
    penToolButton->setGeometry(
                toolButtonPadding,
                pointerToolButton->y()+pointerToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    penToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    penToolButton->setObjectName("toolButton");
    penToolButton->setCheckable(true);

    randomPenToolButton = new QPushButton(QIcon("res/img/GUI/randomPen.png"),"",toolBar);
    randomPenToolButton->setGeometry(
                toolButtonPadding,
                penToolButton->y()+penToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    randomPenToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    randomPenToolButton->setObjectName("toolButton");
    randomPenToolButton->setCheckable(true);

    patternBrushToolButton = new QPushButton(QIcon("res/img/GUI/patternBrush.png"),"", toolBar);
    patternBrushToolButton->setGeometry(
                toolButtonPadding,
                randomPenToolButton->y()+randomPenToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    patternBrushToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    patternBrushToolButton->setObjectName("toolButton");
    patternBrushToolButton->setCheckable(true);

    eraserToolButton = new QPushButton(QIcon("res/img/GUI/eraser.png"),"", toolBar);
    eraserToolButton->setGeometry(
                toolButtonPadding,
                patternBrushToolButton->y()+patternBrushToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    eraserToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    eraserToolButton->setObjectName("toolButton");
    eraserToolButton->setCheckable(true);

    fillShapeToolButton = new QPushButton(QIcon("res/img/GUI/fillShape.png"),"", toolBar);
    fillShapeToolButton->setGeometry(
                toolButtonPadding,
                eraserToolButton->y()+eraserToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    fillShapeToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    fillShapeToolButton->setObjectName("toolButton");
    fillShapeToolButton->setCheckable(true);

    selectAreaToolButton = new QPushButton(QIcon("res/img/GUI/selectArea.png"),"",toolBar);
    selectAreaToolButton->setGeometry(
                toolButtonPadding,
                fillShapeToolButton->y()+fillShapeToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    selectAreaToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    selectAreaToolButton->setObjectName("toolButton");
    selectAreaToolButton->setCheckable(true);

    //

    arrowToolButton = new QPushButton(QIcon("res/img/GUI/arrow.png"),"",toolBar);
    arrowToolButton->setGeometry(
                toolButtonPadding,
                toolSeparatorSize + selectAreaToolButton->y()+selectAreaToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    arrowToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    arrowToolButton->setObjectName("toolButton");
    arrowToolButton->setCheckable(true);

    entityToolButton = new QPushButton(QIcon("res/img/GUI/entity.png"),"",toolBar);
    entityToolButton->setGeometry(
                toolButtonPadding,
                arrowToolButton->y()+arrowToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    entityToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    entityToolButton->setObjectName("toolButton");
    entityToolButton->setCheckable(true);

    objectToolButton = new QPushButton(QIcon("res/img/GUI/object.png"),"", toolBar);
    objectToolButton->setGeometry(
                toolButtonPadding,
                entityToolButton->y()+entityToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    objectToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    objectToolButton->setObjectName("toolButton");
    objectToolButton->setCheckable(true);

    //

    handToolButton = new QPushButton(QIcon("res/img/GUI/hand.png"),"", toolBar);
    handToolButton->setGeometry(
                toolButtonPadding,
                toolSeparatorSize + objectToolButton->y()+objectToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    handToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    handToolButton->setObjectName("toolButton");
    handToolButton->setCheckable(true);

    zoomToolButton = new QPushButton(QIcon("res/img/GUI/zoom.png"),"", toolBar);
    zoomToolButton->setGeometry(
                toolButtonPadding,
                handToolButton->y()+handToolButton->height()+toolButtonPadding,
                toolButtonSize,
                toolButtonSize);
    zoomToolButton->setIconSize(QSize(toolButtonSize,toolButtonSize));
    zoomToolButton->setObjectName("toolButton");
    zoomToolButton->setCheckable(true);

    connect(pointerToolButton,SIGNAL(clicked()),this,SLOT(pointerToolButtonClicked()));
    connect(arrowToolButton,SIGNAL(clicked()),this,SLOT(arrowToolButtonClicked()));
    connect(penToolButton,SIGNAL(clicked()),this,SLOT(penToolButtonClicked()));
    connect(randomPenToolButton,SIGNAL(clicked()),this,SLOT(randomPenToolButtonClicked()));
    connect(patternBrushToolButton,SIGNAL(clicked()),this,SLOT(patternBrushToolButtonClicked()));
    connect(eraserToolButton,SIGNAL(clicked()),this,SLOT(eraserToolButtonClicked()));
    connect(fillShapeToolButton,SIGNAL(clicked()),this,SLOT(fillShapeToolButtonClicked()));
    connect(selectAreaToolButton,SIGNAL(clicked()),this,SLOT(selectAreaToolButtonClicked()));
    connect(entityToolButton,SIGNAL(clicked()),this,SLOT(entityToolButtonClicked()));
    connect(objectToolButton,SIGNAL(clicked()),this,SLOT(objectToolButtonClicked()));
    connect(handToolButton,SIGNAL(clicked()),this,SLOT(handToolButtonClicked()));
    connect(zoomToolButton,SIGNAL(clicked()),this,SLOT(zoomToolButtonClicked()));

}

void Editor::initTopBar()
{
    topBar = new QWidget(this);
    topBar->setGeometry(globalPadding+toolBarWidth,
                        menuBarHeight,
                        width()-toolBarWidth-rightPanelWidth-globalPadding*2,
                        topBarHeight);

    tileButton = new QPushButton(topBar);
    tileButton->setGeometry(2,1,topButtonSize,topButtonSize);
    tileButton->setIconSize(QSize(40,40));
    tileButton->setObjectName("tileButton");
    connect(tileButton,SIGNAL(clicked()),this,SLOT(tileButtonClicked()));
}

void Editor::initRightPanel()
{
    rightPanel = new QWidget(this);
    rightPanel->setGeometry(width()-globalPadding-rightPanelWidth,
                            menuBarHeight,
                            rightPanelWidth,
                            height()-menuBarHeight-globalPadding);

    layerTab = new LayerTab(rightPanel, &map);
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

    sfmlWidget = new SFMLWidget(centralWidget,QPoint(0,0),centralWidget->size(), &map, &camera);

    tileWidget = new TileWidget(centralWidget);
    tileWidget->move(0,0); tileWidget->resize(centralWidget->size());
    connect(tileWidget,SIGNAL(selected(int)),this,SLOT(tileSelected(int)));
    connect(tileWidget,SIGNAL(selected(QPixmap)),this,SLOT(tileSelected(QPixmap)));
    tileWidget->hide();
}

void Editor::quitClicked()
{
    close();
}

void Editor::minimizeClicked()
{
    setWindowState(Qt::WindowMinimized);
}

void Editor::pointerToolButtonClicked()
{
    uncheckToolButtons();
    pointerToolButton->setChecked(true);
    tool=0;
    sfmlWidget->setTool(tool);
}

void Editor::penToolButtonClicked()
{
    uncheckToolButtons();
    penToolButton->setChecked(true);
    tool=1;
    sfmlWidget->setTool(tool);
}

void Editor::randomPenToolButtonClicked()
{
    uncheckToolButtons();
    randomPenToolButton->setChecked(true);
    tool=2;
    sfmlWidget->setTool(tool);
}

void Editor::patternBrushToolButtonClicked()
{
    uncheckToolButtons();
    patternBrushToolButton->setChecked(true);
    tool=3;
    sfmlWidget->setTool(tool);
}

void Editor::eraserToolButtonClicked()
{
    uncheckToolButtons();
    eraserToolButton->setChecked(true);
    tool=4;
    sfmlWidget->setTool(tool);
}

void Editor::fillShapeToolButtonClicked()
{
    uncheckToolButtons();
    fillShapeToolButton->setChecked(true);
    tool=5;
    sfmlWidget->setTool(tool);
}

void Editor::selectAreaToolButtonClicked()
{
    uncheckToolButtons();
    selectAreaToolButton->setChecked(true);
    tool=6;
    sfmlWidget->setTool(tool);
}

void Editor::arrowToolButtonClicked()
{
    uncheckToolButtons();
    arrowToolButton->setChecked(true);
    tool=7;
    sfmlWidget->setTool(tool);
}

void Editor::entityToolButtonClicked()
{
    uncheckToolButtons();
    entityToolButton->setChecked(true);
    tool=8;
    sfmlWidget->setTool(tool);
}

void Editor::objectToolButtonClicked()
{
    uncheckToolButtons();
    objectToolButton->setChecked(true);
    tool=9;
    sfmlWidget->setTool(tool);
}

void Editor::handToolButtonClicked()
{
    uncheckToolButtons();
    handToolButton->setChecked(true);
    tool=10;
    sfmlWidget->setTool(tool);
}

void Editor::zoomToolButtonClicked()
{
    uncheckToolButtons();
    zoomToolButton->setChecked(true);
    tool=11;
    sfmlWidget->setTool(tool);
}


void Editor::uncheckToolButtons()
{
    pointerToolButton->setChecked(false);
    arrowToolButton->setChecked(false);
    penToolButton->setChecked(false);
    randomPenToolButton->setChecked(false);
    patternBrushToolButton->setChecked(false);
    eraserToolButton->setChecked(false);
    fillShapeToolButton->setChecked(false);
    selectAreaToolButton->setChecked(false);
    entityToolButton->setChecked(false);
    objectToolButton->setChecked(false);
    handToolButton->setChecked(false);
    zoomToolButton->setChecked(false);
}


void Editor::tileButtonClicked()
{
    if(tileWidget->isVisible())
        tileWidget->hide();
    else
        tileWidget->show();
}

void Editor::tileSelected(int new_id)
{
    id = new_id;
    sfmlWidget->setCurrentTile(new_id);
}

void Editor::tileSelected(QPixmap tile)
{
    tileButton->setIcon(QIcon(tile));
}

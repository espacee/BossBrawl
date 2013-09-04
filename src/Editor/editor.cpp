#include "editor.h"

Editor::Editor(QWidget *parent) : QWidget(parent),
    gridEnabled(false),
    currentLayer(0)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setGeometry(QApplication::desktop()->availableGeometry());
    setWindowTitle("Editor");
    setWindowIcon(QIcon("res/img/GUI/windowIcon.png"));

    menuBarHeight = 50;
    globalPadding = 5;

    toolBarWidth = 34;
    toolButtonSize = 30;
    toolButtonPadding = 2;
    toolBarTopOffset = 44;
    toolSeparatorSize = 10;

    topBarHeight = 44;
    topButtonSize = 42;

    rightPanelWidth = 300;

    botBarHeight = 22;

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

    connect(layerTab, SIGNAL(layerSelected(int)), sfmlWidget, SLOT(setCurrentLayer(int)));
    connect(layerTab, SIGNAL(layerSelected(int)), this, SLOT(setCurrentLayer(int)));

    i = j = k = 127;
    a = b = c = true;

    fileDialog->setAcceptMode(QFileDialog::AcceptSave);

    onInit();
}

Editor::~Editor()
{

}

void Editor::onInit()
{


    tileWidget->select(0, 0);
    penToolButton->click();
    toggleGridButton->click();

    camera = sf::View(sf::FloatRect(0, 0, sfmlWidget->width() - 1, sfmlWidget->height() - 1));
    camera.setCenter(0, 0);
}

void Editor::onUpdate()
{

    if (a) i += 0.001;
    else i -= 0.001;

    if (i >= 255 || i <= 0) a = !a;

    if (b) j += 0.015;
    else j -= 0.015;

    if (j >= 255 || j <= 0) b = !b;

    if (c) k += 0.005;
    else k -= 0.005;

    if (k >= 255 || k <= 0) c = !c;

    sfmlWidget->processEvents();

    sfmlWidget->clear(sf::Color(i, j, k));

    sfmlWidget->setView(camera);
    map.draw(*sfmlWidget, (gridEnabled ? currentLayer : - 1));

    sfmlWidget->sf::RenderWindow::display();
}

void Editor::initWindow()
{
    windowIcon = new QLabel("", this);
    windowIcon->setPixmap(QPixmap("res/img/GUI/windowIcon.png"));
    windowIcon->setGeometry(0, 0, menuBarHeight, menuBarHeight);

    closeButton = new QPushButton(QIcon("res/img/GUI/close.png"), "", this);
    closeButton->setGeometry(width() - 32, 0, 30, 20);
    closeButton->setObjectName("closeButton");
    connect(closeButton, SIGNAL(clicked()), this, SLOT(quitClicked()));

    minimizeButton = new QPushButton(QIcon("res/img/GUI/minimize.png"), "", this);
    minimizeButton->setGeometry(closeButton->x() - 31, 0, 30, 20);
    minimizeButton->setObjectName("minimizeButton");
    connect(minimizeButton, SIGNAL(clicked()), this, SLOT(minimizeClicked()));

    newButton = new QPushButton("New",this);
    newButton->setGeometry(windowIcon->x()+windowIcon->width()+10, 13,120,25);
    newButton->setObjectName("menuButton");

    openButton = new QPushButton("Open", this);
    openButton->setGeometry(newButton->x()+newButton->width()+5, newButton->y(), newButton->width(),newButton->height());
    openButton->setObjectName("menuButton");

    saveButton = new QPushButton("Save", this);
    saveButton->setGeometry(openButton->x()+openButton->width()+5, openButton->y(), openButton->width(),openButton->height());
    saveButton->setObjectName("menuButton");

    connect(newButton, SIGNAL(clicked()), this, SLOT(newButtonClicked()));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openButtonClicked()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
}

void Editor::initToolBar()
{
    toolBar = new QWidget(this);
    toolBar->setGeometry(globalPadding,
                         menuBarHeight,
                         toolBarWidth,
                         height() - menuBarHeight - globalPadding);

    pointerToolButton = new QPushButton(QIcon("res/img/GUI/pointer.png"), "", toolBar);
    pointerToolButton->setGeometry(
        toolButtonPadding,
        toolButtonPadding + toolBarTopOffset,
        toolButtonSize,
        toolButtonSize);
    pointerToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    pointerToolButton->setObjectName("toolButton");
    pointerToolButton->setCheckable(true);

    penToolButton = new QPushButton(QIcon("res/img/GUI/pen.png"), "", toolBar);
    penToolButton->setGeometry(
        toolButtonPadding,
        pointerToolButton->y() + pointerToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    penToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    penToolButton->setObjectName("toolButton");
    penToolButton->setCheckable(true);

    randomPenToolButton = new QPushButton(QIcon("res/img/GUI/randomPen.png"), "", toolBar);
    randomPenToolButton->setGeometry(
        toolButtonPadding,
        penToolButton->y() + penToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    randomPenToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    randomPenToolButton->setObjectName("toolButton");
    randomPenToolButton->setCheckable(true);

    patternBrushToolButton = new QPushButton(QIcon("res/img/GUI/patternBrush.png"), "", toolBar);
    patternBrushToolButton->setGeometry(
        toolButtonPadding,
        randomPenToolButton->y() + randomPenToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    patternBrushToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    patternBrushToolButton->setObjectName("toolButton");
    patternBrushToolButton->setCheckable(true);

    eraserToolButton = new QPushButton(QIcon("res/img/GUI/eraser.png"), "", toolBar);
    eraserToolButton->setGeometry(
        toolButtonPadding,
        patternBrushToolButton->y() + patternBrushToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    eraserToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    eraserToolButton->setObjectName("toolButton");
    eraserToolButton->setCheckable(true);

    fillShapeToolButton = new QPushButton(QIcon("res/img/GUI/fillShape.png"), "", toolBar);
    fillShapeToolButton->setGeometry(
        toolButtonPadding,
        eraserToolButton->y() + eraserToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    fillShapeToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    fillShapeToolButton->setObjectName("toolButton");
    fillShapeToolButton->setCheckable(true);

    selectAreaToolButton = new QPushButton(QIcon("res/img/GUI/selectArea.png"), "", toolBar);
    selectAreaToolButton->setGeometry(
        toolButtonPadding,
        fillShapeToolButton->y() + fillShapeToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    selectAreaToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    selectAreaToolButton->setObjectName("toolButton");
    selectAreaToolButton->setCheckable(true);

    //

    arrowToolButton = new QPushButton(QIcon("res/img/GUI/arrow.png"), "", toolBar);
    arrowToolButton->setGeometry(
        toolButtonPadding,
        toolSeparatorSize + selectAreaToolButton->y() + selectAreaToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    arrowToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    arrowToolButton->setObjectName("toolButton");
    arrowToolButton->setCheckable(true);

    entityToolButton = new QPushButton(QIcon("res/img/GUI/entity.png"), "", toolBar);
    entityToolButton->setGeometry(
        toolButtonPadding,
        arrowToolButton->y() + arrowToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    entityToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    entityToolButton->setObjectName("toolButton");
    entityToolButton->setCheckable(true);

    objectToolButton = new QPushButton(QIcon("res/img/GUI/object.png"), "", toolBar);
    objectToolButton->setGeometry(
        toolButtonPadding,
        entityToolButton->y() + entityToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    objectToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    objectToolButton->setObjectName("toolButton");
    objectToolButton->setCheckable(true);

    //

    handToolButton = new QPushButton(QIcon("res/img/GUI/hand.png"), "", toolBar);
    handToolButton->setGeometry(
        toolButtonPadding,
        toolSeparatorSize + objectToolButton->y() + objectToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    handToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    handToolButton->setObjectName("toolButton");
    handToolButton->setCheckable(true);

    zoomToolButton = new QPushButton(QIcon("res/img/GUI/zoom.png"), "", toolBar);
    zoomToolButton->setGeometry(
        toolButtonPadding,
        handToolButton->y() + handToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    zoomToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    zoomToolButton->setObjectName("toolButton");
    zoomToolButton->setCheckable(true);

    connect(pointerToolButton, SIGNAL(clicked()), this, SLOT(pointerToolButtonClicked()));
    connect(arrowToolButton, SIGNAL(clicked()), this, SLOT(arrowToolButtonClicked()));
    connect(penToolButton, SIGNAL(clicked()), this, SLOT(penToolButtonClicked()));
    connect(randomPenToolButton, SIGNAL(clicked()), this, SLOT(randomPenToolButtonClicked()));
    connect(patternBrushToolButton, SIGNAL(clicked()), this, SLOT(patternBrushToolButtonClicked()));
    connect(eraserToolButton, SIGNAL(clicked()), this, SLOT(eraserToolButtonClicked()));
    connect(fillShapeToolButton, SIGNAL(clicked()), this, SLOT(fillShapeToolButtonClicked()));
    connect(selectAreaToolButton, SIGNAL(clicked()), this, SLOT(selectAreaToolButtonClicked()));
    connect(entityToolButton, SIGNAL(clicked()), this, SLOT(entityToolButtonClicked()));
    connect(objectToolButton, SIGNAL(clicked()), this, SLOT(objectToolButtonClicked()));
    connect(handToolButton, SIGNAL(clicked()), this, SLOT(handToolButtonClicked()));
    connect(zoomToolButton, SIGNAL(clicked()), this, SLOT(zoomToolButtonClicked()));

}

void Editor::initTopBar()
{
    topBar = new QWidget(this);
    topBar->setGeometry(globalPadding + toolBarWidth,
                        menuBarHeight,
                        width() - toolBarWidth - rightPanelWidth - globalPadding * 2,
                        topBarHeight);

    tileButton = new QPushButton(topBar);
    tileButton->setGeometry(2, 1, topButtonSize, topButtonSize);
    tileButton->setIconSize(QSize(40, 40));
    tileButton->setObjectName("tileButton");
    tileButton->setShortcut(QKeySequence("A"));
    connect(tileButton, SIGNAL(clicked()), this, SLOT(tileButtonClicked()));
}

void Editor::initRightPanel()
{
    rightPanel = new QWidget(this);
    rightPanel->setGeometry(width() - globalPadding - rightPanelWidth,
                            menuBarHeight,
                            rightPanelWidth,
                            height() - menuBarHeight - globalPadding);

    layerTab = new LayerTab(rightPanel, map);
    layerTab->resize(rightPanel->size());
}

void Editor::initBotBar()
{
    botBar = new QWidget(this);
    botBar->setGeometry(globalPadding + toolBarWidth,
                        height() - globalPadding - botBarHeight,
                        width() - toolBarWidth - rightPanelWidth - globalPadding * 2,
                        botBarHeight);

    resetCameraButton = new QPushButton(QIcon("res/img/GUI/camera.png"), "", botBar);
    resetCameraButton->setGeometry(1, 2, botBarHeight - 2, botBarHeight - 2);
    resetCameraButton->setIconSize(resetCameraButton->size());
    resetCameraButton->setObjectName("toolButton");

    toggleGridButton = new QPushButton(QIcon("res/img/GUI/grid.png"), "", botBar);
    toggleGridButton->setGeometry(resetCameraButton->x() + resetCameraButton->width() + 2, 1, botBarHeight - 2, botBarHeight - 2);
    toggleGridButton->setIconSize(toggleGridButton->size());
    toggleGridButton->setObjectName("toolButton");
    toggleGridButton->setCheckable(true);
    toggleGridButton->setShortcut(QKeySequence("Ctrl+G"));

    toggleVisibleButton = new QPushButton(QIcon("res/img/GUI/eye.png"), "", botBar);
    toggleVisibleButton->setGeometry(toggleGridButton->x() + toggleGridButton->width() + 2, 1, botBarHeight - 2, botBarHeight - 2);
    toggleVisibleButton->setIconSize(toggleVisibleButton->size());
    toggleVisibleButton->setObjectName("toolButton");
    toggleVisibleButton->setCheckable(true);
    toggleVisibleButton->setShortcut(QKeySequence("Ctrl+V"));

    connect(resetCameraButton, SIGNAL(clicked()), this, SLOT(resetCameraButtonClicked()));
    connect(toggleGridButton, SIGNAL(clicked()), this, SLOT(toggleGridButtonClicked()));
    connect(toggleVisibleButton, SIGNAL(clicked()), this, SLOT(toggleVisibleButtonClicked()));

}

void Editor::initCentralWidget()
{
    centralWidget = new QWidget(this);
    centralWidget->setGeometry(toolBar->x() + toolBar->width(),
                               topBar->y() + topBar->height(),
                               width() - toolBar->x() - toolBar->width() - rightPanelWidth - globalPadding,
                               height() - menuBarHeight - topBarHeight - globalPadding - botBarHeight);

    sfmlWidget = new SFMLWidget(centralWidget, QPoint(0, 0), centralWidget->size(), map, &camera);

    tileWidget = new TileWidget(centralWidget);
    tileWidget->move(0, 0);
    tileWidget->resize(centralWidget->size());
    connect(tileWidget, SIGNAL(selected(int)), this, SLOT(tileSelected(int)));
    connect(tileWidget, SIGNAL(selected(QPixmap)), this, SLOT(tileSelected(QPixmap)));
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
    tool = 0;
    sfmlWidget->setTool(tool);
}

void Editor::penToolButtonClicked()
{
    uncheckToolButtons();
    penToolButton->setChecked(true);
    tool = 1;
    sfmlWidget->setTool(tool);
}

void Editor::randomPenToolButtonClicked()
{
    uncheckToolButtons();
    randomPenToolButton->setChecked(true);
    tool = 2;
    sfmlWidget->setTool(tool);
}

void Editor::patternBrushToolButtonClicked()
{
    uncheckToolButtons();
    patternBrushToolButton->setChecked(true);
    tool = 3;
    sfmlWidget->setTool(tool);
}

void Editor::eraserToolButtonClicked()
{
    uncheckToolButtons();
    eraserToolButton->setChecked(true);
    tool = 4;
    sfmlWidget->setTool(tool);
}

void Editor::fillShapeToolButtonClicked()
{
    uncheckToolButtons();
    fillShapeToolButton->setChecked(true);
    tool = 5;
    sfmlWidget->setTool(tool);
}

void Editor::selectAreaToolButtonClicked()
{
    uncheckToolButtons();
    selectAreaToolButton->setChecked(true);
    tool = 6;
    sfmlWidget->setTool(tool);
}

void Editor::arrowToolButtonClicked()
{
    uncheckToolButtons();
    arrowToolButton->setChecked(true);
    tool = 7;
    sfmlWidget->setTool(tool);
}

void Editor::entityToolButtonClicked()
{
    uncheckToolButtons();
    entityToolButton->setChecked(true);
    tool = 8;
    sfmlWidget->setTool(tool);
}

void Editor::objectToolButtonClicked()
{
    uncheckToolButtons();
    objectToolButton->setChecked(true);
    tool = 9;
    sfmlWidget->setTool(tool);
}

void Editor::handToolButtonClicked()
{
    uncheckToolButtons();
    handToolButton->setChecked(true);
    tool = 10;
    sfmlWidget->setTool(tool);
}

void Editor::zoomToolButtonClicked()
{
    uncheckToolButtons();
    zoomToolButton->setChecked(true);
    tool = 11;
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
    if (tileWidget->isVisible())
        tileWidget->hide();
    else
        tileWidget->show();
}
void Editor::newButtonClicked()
{


}
void Editor::openButtonClicked()
{
     std::string filename = QFileDialog::getOpenFileName(this).toStdString();//getting the file name

    if (map.loadFromFile(filename))
    {
        layerTab->loadLayersFromMap();
    }

    filePath = filename;
}
void Editor::saveButtonClicked()
{
    if(filePath.empty() == true)
    {
     filePath = QFileDialog::getSaveFileName(this).toStdString();
     map.saveToFile(filePath);
    }
    else
    {
        map.saveToFile(filePath);
    }
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

void Editor::setCurrentLayer(int layer)
{
    currentLayer = layer;
}

void Editor::resetCameraButtonClicked()
{
    camera = sf::View(sf::FloatRect(0, 0, sfmlWidget->width() - 1, sfmlWidget->height() - 1));
    camera.setCenter(0, 0);
}

void Editor::toggleGridButtonClicked()
{
    gridEnabled = !gridEnabled;
}

void Editor::toggleVisibleButtonClicked()
{
    layerTab->toggleVisible();
}


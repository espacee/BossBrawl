#include "MainWidget.hpp"
#include <QMessageBox>
#include "tools.hpp"
#include "maps.hpp"

MainWidget::MainWidget(QWidget *parent_) : 
    QWidget(parent_)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setGeometry(QApplication::desktop()->availableGeometry());
    setWindowTitle("Editor");
    setWindowIcon(QIcon("res/img/GUI/windowIcon.png"));
    menuBarHeight = 50;
    globalPadding = 5;
    toolBarWidth = 34;
    topBarHeight = 44;
    topButtonSize = 42;
    rightPanelWidth = 300;
    botBarHeight = 22;
    initWindow();
    toolBar = new ToolbarWidget(this);
    toolBar->setGeometry(globalPadding,
                         menuBarHeight,
                         toolBarWidth,
                         height() - menuBarHeight - globalPadding);
    initRightPanel();
    initTopBar();
    initBotBar();
    initCentralWidget();
    toolBar->setMapWidget(m_mapWidget);
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
    connect(layerTab, SIGNAL(layerSelected(int)), m_mapWidget, SLOT(setCurrentLayer(int)));
    // If given a command line argument, load it as a map
    auto args = QApplication::arguments();

    if (args.size() > 1)
    {
        loadMapFromFile(args.at(1));
    }
    else
    {
        newMap();
    }
    
    onInit();
}

MainWidget::~MainWidget()
{
    maps::cleanup();
}

void MainWidget::onInit()
{
    tileWidget->select(0, 0);
    toolBar->doInitialClicks();
    toggleGridButton->click();
}

void MainWidget::onUpdate()
{
    m_mapWidget->render();
}

void MainWidget::initWindow()
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
    newButton = new QPushButton("New", this);
    newButton->setGeometry(windowIcon->x() + windowIcon->width() + 10, 13, 120, 25);
    newButton->setObjectName("menuButton");
    openButton = new QPushButton("Open", this);
    openButton->setGeometry(newButton->x() + newButton->width() + 5, newButton->y(), newButton->width(), newButton->height());
    openButton->setObjectName("menuButton");
    saveButton = new QPushButton("Save", this);
    saveButton->setGeometry(openButton->x() + openButton->width() + 5, openButton->y(), openButton->width(), openButton->height());
    saveButton->setObjectName("menuButton");
    connect(newButton, SIGNAL(clicked()), this, SLOT(newButtonClicked()));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openButtonClicked()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
}

void MainWidget::initTopBar()
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

void MainWidget::initRightPanel()
{
    rightPanel = new QWidget(this);
    rightPanel->setGeometry(width() - globalPadding - rightPanelWidth,
                            menuBarHeight,
                            rightPanelWidth,
                            height() - menuBarHeight - globalPadding);
    layerTab = new LayerListWidget(rightPanel);
    layerTab->resize(rightPanel->size());
}

void MainWidget::initBotBar()
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

void MainWidget::initCentralWidget()
{
    centralWidget = new QWidget(this);
    centralWidget->setGeometry(toolBar->x() + toolBar->width(),
                               topBar->y() + topBar->height(),
                               width() - toolBar->x() - toolBar->width() - rightPanelWidth - globalPadding,
                               height() - menuBarHeight - topBarHeight - globalPadding - botBarHeight);
    m_mapWidget = new MapWidget(centralWidget, QPoint(0, 0), centralWidget->size());
    tileWidget = new TileSelectionWidget(centralWidget);
    tileWidget->move(0, 0);
    tileWidget->resize(centralWidget->size());
    connect(tileWidget, SIGNAL(selected(int)), this, SLOT(tileSelected(int)));
    connect(tileWidget, SIGNAL(selected(QPixmap)), this, SLOT(tileSelected(QPixmap)));
    tileWidget->hide();
}

void MainWidget::loadMapFromFile(const QString &filename)
{
    if (!maps::loadFromFile(filename))
    {
        QMessageBox::critical(this, "Error", tr("Could not load \"%1\" as a map").arg(filename));
        return;
    }
    maps::setActive(maps::size() - 1);
    layerTab->loadLayersFromMap();
    std::string entityfilename = filename.toStdString();
    int entityfilenamesize = entityfilename.size() - 4;
    entityfilename.replace(entityfilenamesize, 4, ".entity");
    maps::currentEntityContainer().loadFromFile(entityfilename);
    filePath = filename.toStdString();
}

void MainWidget::newMap()
{
    maps::addNew();
    maps::setActive(maps::size() - 1);
}

void MainWidget::quitClicked()
{
    close();
}

void MainWidget::minimizeClicked()
{
    setWindowState(Qt::WindowMinimized);
}

void MainWidget::tileButtonClicked()
{
    if (tileWidget->isVisible())
        tileWidget->hide();
    else
        tileWidget->show();
}
void MainWidget::newButtonClicked()
{
    maps::current().reset();
    maps::currentEntityContainer().reset();
    layerTab->loadLayersFromMap();
}

void MainWidget::openButtonClicked()
{
    QString filename = QFileDialog::getOpenFileName(this);

    if (!filename.isNull())
        loadMapFromFile(filename);
}
void MainWidget::saveButtonClicked()
{
    if (filePath.empty() == true)
    {
        filePath = QFileDialog::getSaveFileName(this).toStdString();
        maps::current().saveToFile(filePath + ".map");
        maps::currentEntityContainer().saveToFile(filePath + ".entity");
    }
    else
    {
        maps::current().saveToFile(filePath);
        std::string entityfilename = filePath;
        int entityfilenamesize = entityfilename.size() - 4;
        entityfilename.replace(entityfilenamesize, 4, ".entity");
        maps::currentEntityContainer().saveToFile(entityfilename);
    }
}
void MainWidget::tileSelected(int new_id)
{
    id = new_id;
    m_mapWidget->setCurrentTile(new_id);
}

void MainWidget::tileSelected(QPixmap tile)
{
    tileButton->setIcon(QIcon(tile));
}

void MainWidget::resetCameraButtonClicked()
{
    m_mapWidget->resetCamera();
}

void MainWidget::toggleGridButtonClicked()
{
    m_mapWidget->toggleGrid();
}

void MainWidget::toggleVisibleButtonClicked()
{
    layerTab->toggleVisible();
}

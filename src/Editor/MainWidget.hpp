#ifndef MAINWIDGET_HPP
#define MAINWIDGET_HPP

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QTimer>
#include <QFileDialog>

#include "MapWidget.hpp"
#include "TileSelectionWidget.hpp"
#include "LayerListWidget.hpp"
#include "Map/TileMap.hpp"
#include "Entities/EntityContainer.hpp"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

public slots:
    void onInit();
    void onUpdate();
    void quitClicked();
    void minimizeClicked();

    void pointerToolButtonClicked();
    void arrowToolButtonClicked();
    void penToolButtonClicked();
    void randomPenToolButtonClicked();
    void patternBrushToolButtonClicked();
    void eraserToolButtonClicked();
    void fillShapeToolButtonClicked();
    void selectAreaToolButtonClicked();
    void entityToolButtonClicked();
    void objectToolButtonClicked();
    void handToolButtonClicked();
    void zoomToolButtonClicked();
    void newButtonClicked();
    void openButtonClicked();
    void saveButtonClicked();

    void resetCameraButtonClicked();
    void toggleGridButtonClicked();
    void toggleVisibleButtonClicked();

    void uncheckToolButtons();

    void tileButtonClicked();
    void tileSelected(int new_id);
    void tileSelected(QPixmap tile);

    void setCurrentLayer(int layer);

private:

    TileMap map;
    EntityContainer cont;

    QTimer timer;
    unsigned int frameTime;

    void initWindow();
    void initToolBar();
    void initTopBar();
    void initRightPanel();
    void initBotBar();
    void initCentralWidget();
    void loadMapFromFile(const QString &filename);

    int menuBarHeight, globalPadding;
    int toolBarWidth, toolButtonSize, toolButtonPadding, toolBarTopOffset, toolSeparatorSize;
    int topBarHeight, topButtonSize;
    int rightPanelWidth;
    int botBarHeight;

    float clear_red, clear_green, clear_blue;
    bool a, b, c;

    MapWidget* m_mapWidget;
    sf::View camera;

    QWidget *toolBar;
    QWidget *topBar;
    QWidget *rightPanel;
    QWidget *botBar;
    QWidget *centralWidget;

    QLabel* windowIcon;
    QPushButton* minimizeButton;
    QPushButton* closeButton;
    QPushButton* newButton;
    QPushButton* openButton;
    QPushButton* saveButton;

    QPushButton* pointerToolButton;
    QPushButton* penToolButton;
    QPushButton* randomPenToolButton;
    QPushButton* patternBrushToolButton;
    QPushButton* eraserToolButton;
    QPushButton* fillShapeToolButton;
    QPushButton* selectAreaToolButton;
    QPushButton* arrowToolButton;
    QPushButton* entityToolButton;
    QPushButton* objectToolButton;
    QPushButton* handToolButton;
    QPushButton* zoomToolButton;

    QPushButton* resetCameraButton;
    QPushButton* toggleGridButton;
    QPushButton* toggleVisibleButton;

    TileSelectionWidget* tileWidget;
    int id;

    QPushButton* tileButton;

    LayerListWidget* layerTab;
    bool gridEnabled;
    int currentLayer, mainLayer;

    QFileDialog* fileDialog = new QFileDialog;
    std::string filePath;
};

#endif // MAINWIDGET_HPP

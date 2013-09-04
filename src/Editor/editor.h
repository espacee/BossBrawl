#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QTimer>
#include <QFileDialog>

#include "Editor/sfmlwidget.h"
#include "Editor/tilewidget.h"
#include "Editor/layertab.h"
#include "Map/TileMap.hpp"

class Editor : public QWidget
{
    Q_OBJECT

public:
    Editor(QWidget *parent = 0);
    ~Editor();

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

    QTimer timer;
    unsigned int frameTime;

    void initWindow();
    void initToolBar();
    void initTopBar();
    void initRightPanel();
    void initBotBar();
    void initCentralWidget();

    int menuBarHeight, globalPadding;
    int toolBarWidth, toolButtonSize, toolButtonPadding, toolBarTopOffset, toolSeparatorSize;
    int topBarHeight, topButtonSize;
    int rightPanelWidth;
    int botBarHeight;

    float i, j, k;
    bool a, b, c;

    SFMLWidget* sfmlWidget;
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

    int tool;
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

    TileWidget* tileWidget;
    int id;

    QPushButton* tileButton;

    LayerTab* layerTab;
    bool gridEnabled;
    int currentLayer;

    QFileDialog* fileDialog = new QFileDialog;
    std::string filePath;

};

#endif // WINDOW_H

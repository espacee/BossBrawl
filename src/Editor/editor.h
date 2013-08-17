#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QTimer>

#include "Editor/sfmlwidget.h"
#include "Editor/tilewidget.h"
#include "Editor/layerwidget.h"
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

    void uncheckToolButtons();

    void tileButtonClicked();
    void tileSelected(int new_id);
    void tileSelected(QPixmap tile);

    void addLayerButtonClicked();
    void removeLayerButtonClicked();

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

    float i,j,k;
    bool a,b,c;

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

    TileWidget* tileWidget;
    int id;

    QPushButton* tileButton;

    QWidget* layerTab;
    QScrollArea* layerScrollArea;
    QPushButton* addLayerButton;
    QPushButton* removeLayerButton;

};

#endif // WINDOW_H

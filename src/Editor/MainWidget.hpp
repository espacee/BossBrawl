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

#include "TileSelectionWidget.hpp"
#include "LayerListWidget.hpp"
#include "ToolbarWidget.hpp"
#include "BottomBarWidget.hpp"

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

    void newButtonClicked();
    void openButtonClicked();
    void saveButtonClicked();

    void tileButtonClicked();
    void tileSelected(int new_id);
    void tileSelected(QPixmap tile);

private:
    QTimer timer;
    unsigned int frameTime;

    void initWindow();
    void initTopBar();
    void initRightPanel();
    void initBotBar();
    void initCentralWidget();
    void loadMapFromFile(const QString &filename);
    void newMap();

    int menuBarHeight, globalPadding;
    int toolBarWidth;
    int topBarHeight, topButtonSize;
    int rightPanelWidth;
    int botBarHeight;

    ToolbarWidget *toolBar;
    QWidget *topBar;
    QWidget *rightPanel;
    BottomBarWidget *botBar;
    QWidget *centralWidget;

    QLabel *windowIcon;
    QPushButton *minimizeButton;
    QPushButton *closeButton;
    QPushButton *newButton;
    QPushButton *openButton;
    QPushButton *saveButton;

    TileSelectionWidget *tileWidget;
    int id;

    QPushButton *tileButton;

    LayerListWidget *layerTab;
    int mainLayer;

    std::string filePath;
};

#endif // MAINWIDGET_HPP

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QTimer>

#include "sfmlwidget.h"

class Editor : public QWidget
{
    Q_OBJECT
    
public:
    Editor(QWidget *parent = 0);
    ~Editor();

public slots:
    void onUpdate();
    void quitClicked();
    void minimizeClicked();

private:

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
    int topBarHeight;
    int rightPanelWidth;
    int botBarHeight;

    int i,j,k;
    bool a,b,c;

    QWidget *toolBar;
    QWidget *topBar;
    QWidget *rightPanel;
    QWidget *botBar;
    QWidget *centralWidget;

    QLabel* windowIcon;
    QPushButton* minimizeButton;
    QPushButton* closeButton;

    QPushButton* pointerToolButton;
    QPushButton* arrowToolButton;
    QPushButton* penToolButton;
    QPushButton* randomPenToolButton;
    QPushButton* patternBrushToolButton;
    QPushButton* eraserToolButton;
    QPushButton* fillShapeToolButton;
    QPushButton* selectAreaToolButton;
    QPushButton* entityToolButton;
    QPushButton* objectToolButton;
    QPushButton* handToolButton;
    QPushButton* zoomToolButton;

    SFMLWidget* sfmlWidget;
};

#endif // WINDOW_H

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>

class Window : public QWidget
{
    Q_OBJECT
    
public:
    Window(QWidget *parent = 0);
    ~Window();

public slots:
    void quitClicked();
    void minimizeClicked();

private:

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

    QWidget *toolBar;
    QWidget *topBar;
    QWidget *rightPanel;
    QWidget *botBar;
    QWidget *centralWidget;

    QLabel* windowIcon;
    QPushButton* minimizeButton;
    QPushButton* closeButton;

    QLabel* toolBarTitle;
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
};

#endif // WINDOW_H

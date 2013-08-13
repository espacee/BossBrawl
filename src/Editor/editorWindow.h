#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>

class Window : public QWidget
{
    Q_OBJECT
    
public:
    Window(QWidget *parent = 0);
    ~Window();

    void showEvent(QShowEvent*);

private:
    int menuBarHeight, globalPadding, toolBarWidth, topBarHeight, rightPanelWidth, botBarHeight;
    QWidget *toolBar, *topBar, *rightPanel, *botBar, *centralWidget;

};

#endif // WINDOW_H

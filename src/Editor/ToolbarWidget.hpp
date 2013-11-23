#ifndef TOOLBARWIDGET_HPP
#define TOOLBARWIDGET_HPP

#include <QWidget>
#include <QPushButton>
#include "MapWidget.hpp"
#include "tools.hpp"

class ToolbarWidget : public QWidget {
    Q_OBJECT
public:
    ToolbarWidget(QWidget *parent_);
    void doInitialClicks();
    void setMapWidget(MapWidget *mw);
private:
    QPushButton *m_buttons[TOOL_COUNT];
    MapWidget *m_mapWidget;
};

#endif // TOOLBARWIDGET_HPP

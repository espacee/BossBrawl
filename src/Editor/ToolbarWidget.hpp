#ifndef TOOLBARWIDGET_HPP
#define TOOLBARWIDGET_HPP

#include <QWidget>
#include <QPushButton>
#include "MapWidget.hpp"

class ToolbarWidget : public QWidget {
    Q_OBJECT
public:
    ToolbarWidget(QWidget *parent_);
    void uncheckAll();
    void doInitialClicks();
    void setMapWidget(MapWidget *mw);
private slots:
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
private:
    QPushButton *pointerToolButton;
    QPushButton *penToolButton;
    QPushButton *randomPenToolButton;
    QPushButton *patternBrushToolButton;
    QPushButton *eraserToolButton;
    QPushButton *fillShapeToolButton;
    QPushButton *selectAreaToolButton;
    QPushButton *arrowToolButton;
    QPushButton *entityToolButton;
    QPushButton *objectToolButton;
    QPushButton *handToolButton;
    QPushButton *zoomToolButton;
    int toolButtonSize, toolButtonPadding, toolBarTopOffset, toolSeparatorSize;
    MapWidget *m_mapWidget;
};

#endif // TOOLBARWIDGET_HPP

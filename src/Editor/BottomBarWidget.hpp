#ifndef BOTTOMBARWIDGET_HPP
#define BOTTOMBARWIDGET_HPP

#include <QWidget>
#include <QPushButton>
#include "LayerListWidget.hpp"
#include "MapWidget.hpp"

class BottomBarWidget : public QWidget {
    Q_OBJECT
public:
    BottomBarWidget(QWidget *parent_);
    void doInitialClicks();
    void setMapWidgetAndLayerListWidget(MapWidget *mw, LayerListWidget *llw);
private slots:
    void resetCameraButtonClicked();
    void toggleGridButtonClicked();
    void toggleVisibleButtonClicked();
private:
    QPushButton *resetCameraButton;
    QPushButton *toggleGridButton;
    QPushButton *toggleVisibleButton;
    LayerListWidget *layerTab;
    MapWidget *m_mapWidget;
};

#endif // BOTTOMBARWIDGET_HPP

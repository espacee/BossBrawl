#ifndef BOTTOMBARWIDGET_HPP
#define BOTTOMBARWIDGET_HPP

#include <QWidget>
#include <QPushButton>
#include "LayerListWidget.hpp"

class BottomBarWidget : public QWidget {
    Q_OBJECT
public:
    BottomBarWidget(QWidget *parent_);
    void doInitialClicks();
    void setLayerListWidget(LayerListWidget *llw);
private slots:
    void resetCameraButtonClicked();
    void toggleGridButtonClicked();
    void toggleVisibleButtonClicked();
private:
    QPushButton *resetCameraButton;
    QPushButton *toggleGridButton;
    QPushButton *toggleVisibleButton;
    LayerListWidget *layerTab;
};

#endif // BOTTOMBARWIDGET_HPP

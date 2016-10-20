#include "BottomBarWidget.hpp"
#include "MapWidget.hpp"

/**

BOTTOM BAR 

**/

BottomBarWidget::BottomBarWidget(QWidget *parent_) :
    QWidget(parent_)
{
    const int botBarHeight = 22;
    resetCameraButton = new QPushButton(QIcon("res/img/GUI/camera.png"), "", this);
    resetCameraButton->setGeometry(1, 2, botBarHeight - 2, botBarHeight - 2);
    resetCameraButton->setIconSize(resetCameraButton->size());
    resetCameraButton->setObjectName("toolButton");
    toggleGridButton = new QPushButton(QIcon("res/img/GUI/grid.png"), "", this);
    toggleGridButton->setGeometry(resetCameraButton->x() + resetCameraButton->width() + 2, 1, botBarHeight - 2, botBarHeight - 2);
    toggleGridButton->setIconSize(toggleGridButton->size());
    toggleGridButton->setObjectName("toolButton");
    toggleGridButton->setCheckable(true);
    toggleGridButton->setShortcut(QKeySequence("Ctrl+G"));
    toggleVisibleButton = new QPushButton(QIcon("res/img/GUI/eye.png"), "", this);
    toggleVisibleButton->setGeometry(toggleGridButton->x() + toggleGridButton->width() + 2, 1, botBarHeight - 2, botBarHeight - 2);
    toggleVisibleButton->setIconSize(toggleVisibleButton->size());
    toggleVisibleButton->setObjectName("toolButton");
    toggleVisibleButton->setCheckable(true);
    toggleVisibleButton->setShortcut(QKeySequence("Ctrl+V"));
    connect(resetCameraButton, SIGNAL(clicked()), this, SLOT(resetCameraButtonClicked()));
    connect(toggleGridButton, SIGNAL(clicked()), this, SLOT(toggleGridButtonClicked()));
    connect(toggleVisibleButton, SIGNAL(clicked()), this, SLOT(toggleVisibleButtonClicked()));
}

void BottomBarWidget::doInitialClicks()
{
    toggleGridButton->click();
}

void BottomBarWidget::setLayerListWidget(LayerListWidget *llw)
{
    layerTab = llw;
}

/**
RESET DE CAMERA 
**/
void BottomBarWidget::resetCameraButtonClicked()
{
    mapWidget->resetCamera();
}

/**
Toggle GRID
**/
void BottomBarWidget::toggleGridButtonClicked()
{
    mapWidget->toggleGrid();
}

void BottomBarWidget::toggleVisibleButtonClicked()
{
    layerTab->toggleVisible();
}

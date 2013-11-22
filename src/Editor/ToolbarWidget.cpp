#include "ToolbarWidget.hpp"
#include "tools.hpp"
#include <QDebug>

ToolbarWidget::ToolbarWidget(QWidget *parent_) :
    QWidget(parent_)
{
    toolButtonSize = 30;
    toolButtonPadding = 2;
    toolBarTopOffset = 44;
    toolSeparatorSize = 10;
    pointerToolButton = new QPushButton(QIcon("res/img/GUI/pointer.png"), "", this);
    pointerToolButton->setGeometry(
        toolButtonPadding,
        toolButtonPadding + toolBarTopOffset,
        toolButtonSize,
        toolButtonSize);
    pointerToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    pointerToolButton->setObjectName("toolButton");
    pointerToolButton->setCheckable(true);
    penToolButton = new QPushButton(QIcon("res/img/GUI/pen.png"), "", this);
    penToolButton->setGeometry(
        toolButtonPadding,
        pointerToolButton->y() + pointerToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    penToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    penToolButton->setObjectName("toolButton");
    penToolButton->setCheckable(true);
    randomPenToolButton = new QPushButton(QIcon("res/img/GUI/randomPen.png"), "", this);
    randomPenToolButton->setGeometry(
        toolButtonPadding,
        penToolButton->y() + penToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    randomPenToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    randomPenToolButton->setObjectName("toolButton");
    randomPenToolButton->setCheckable(true);
    patternBrushToolButton = new QPushButton(QIcon("res/img/GUI/patternBrush.png"), "", this);
    patternBrushToolButton->setGeometry(
        toolButtonPadding,
        randomPenToolButton->y() + randomPenToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    patternBrushToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    patternBrushToolButton->setObjectName("toolButton");
    patternBrushToolButton->setCheckable(true);
    eraserToolButton = new QPushButton(QIcon("res/img/GUI/eraser.png"), "", this);
    eraserToolButton->setGeometry(
        toolButtonPadding,
        patternBrushToolButton->y() + patternBrushToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    eraserToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    eraserToolButton->setObjectName("toolButton");
    eraserToolButton->setCheckable(true);
    fillShapeToolButton = new QPushButton(QIcon("res/img/GUI/fillShape.png"), "", this);
    fillShapeToolButton->setGeometry(
        toolButtonPadding,
        eraserToolButton->y() + eraserToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    fillShapeToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    fillShapeToolButton->setObjectName("toolButton");
    fillShapeToolButton->setCheckable(true);
    selectAreaToolButton = new QPushButton(QIcon("res/img/GUI/selectArea.png"), "", this);
    selectAreaToolButton->setGeometry(
        toolButtonPadding,
        fillShapeToolButton->y() + fillShapeToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    selectAreaToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    selectAreaToolButton->setObjectName("toolButton");
    selectAreaToolButton->setCheckable(true);
    //
    arrowToolButton = new QPushButton(QIcon("res/img/GUI/arrow.png"), "", this);
    arrowToolButton->setGeometry(
        toolButtonPadding,
        toolSeparatorSize + selectAreaToolButton->y() + selectAreaToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    arrowToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    arrowToolButton->setObjectName("toolButton");
    arrowToolButton->setCheckable(true);
    entityToolButton = new QPushButton(QIcon("res/img/GUI/entity.png"), "", this);
    entityToolButton->setGeometry(
        toolButtonPadding,
        arrowToolButton->y() + arrowToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    entityToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    entityToolButton->setObjectName("toolButton");
    entityToolButton->setCheckable(true);
    objectToolButton = new QPushButton(QIcon("res/img/GUI/object.png"), "", this);
    objectToolButton->setGeometry(
        toolButtonPadding,
        entityToolButton->y() + entityToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    objectToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    objectToolButton->setObjectName("toolButton");
    objectToolButton->setCheckable(true);
    //
    handToolButton = new QPushButton(QIcon("res/img/GUI/hand.png"), "", this);
    handToolButton->setGeometry(
        toolButtonPadding,
        toolSeparatorSize + objectToolButton->y() + objectToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    handToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    handToolButton->setObjectName("toolButton");
    handToolButton->setCheckable(true);
    zoomToolButton = new QPushButton(QIcon("res/img/GUI/zoom.png"), "", this);
    zoomToolButton->setGeometry(
        toolButtonPadding,
        handToolButton->y() + handToolButton->height() + toolButtonPadding,
        toolButtonSize,
        toolButtonSize);
    zoomToolButton->setIconSize(QSize(toolButtonSize, toolButtonSize));
    zoomToolButton->setObjectName("toolButton");
    zoomToolButton->setCheckable(true);
    connect(pointerToolButton, SIGNAL(clicked()), this, SLOT(pointerToolButtonClicked()));
    connect(arrowToolButton, SIGNAL(clicked()), this, SLOT(arrowToolButtonClicked()));
    connect(penToolButton, SIGNAL(clicked()), this, SLOT(penToolButtonClicked()));
    connect(randomPenToolButton, SIGNAL(clicked()), this, SLOT(randomPenToolButtonClicked()));
    connect(patternBrushToolButton, SIGNAL(clicked()), this, SLOT(patternBrushToolButtonClicked()));
    connect(eraserToolButton, SIGNAL(clicked()), this, SLOT(eraserToolButtonClicked()));
    connect(fillShapeToolButton, SIGNAL(clicked()), this, SLOT(fillShapeToolButtonClicked()));
    connect(selectAreaToolButton, SIGNAL(clicked()), this, SLOT(selectAreaToolButtonClicked()));
    connect(entityToolButton, SIGNAL(clicked()), this, SLOT(entityToolButtonClicked()));
    connect(objectToolButton, SIGNAL(clicked()), this, SLOT(objectToolButtonClicked()));
    connect(handToolButton, SIGNAL(clicked()), this, SLOT(handToolButtonClicked()));
    connect(zoomToolButton, SIGNAL(clicked()), this, SLOT(zoomToolButtonClicked()));
}

void ToolbarWidget::uncheckAll()
{
    pointerToolButton->setChecked(false);
    arrowToolButton->setChecked(false);
    penToolButton->setChecked(false);
    randomPenToolButton->setChecked(false);
    patternBrushToolButton->setChecked(false);
    eraserToolButton->setChecked(false);
    fillShapeToolButton->setChecked(false);
    selectAreaToolButton->setChecked(false);
    entityToolButton->setChecked(false);
    objectToolButton->setChecked(false);
    handToolButton->setChecked(false);
    zoomToolButton->setChecked(false);
}

void ToolbarWidget::doInitialClicks()
{
    penToolButton->click();
}

void ToolbarWidget::setMapidget(MapWidget *mw)
{
    m_mapWidget = mw;
}

void ToolbarWidget::pointerToolButtonClicked()
{
    uncheckAll();
    pointerToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::Pointer);
}

void ToolbarWidget::penToolButtonClicked()
{
    uncheckAll();
    penToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::Pen);
}

void ToolbarWidget::randomPenToolButtonClicked()
{
    uncheckAll();
    randomPenToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::RandomPen);
}

void ToolbarWidget::patternBrushToolButtonClicked()
{
    uncheckAll();
    patternBrushToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::PatternBrush);
}

void ToolbarWidget::eraserToolButtonClicked()
{
    uncheckAll();
    eraserToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::Eraser);
}

void ToolbarWidget::fillShapeToolButtonClicked()
{
    uncheckAll();
    fillShapeToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::FillShape);
}

void ToolbarWidget::selectAreaToolButtonClicked()
{
    uncheckAll();
    selectAreaToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::SelectArea);
}

void ToolbarWidget::arrowToolButtonClicked()
{
    uncheckAll();
    arrowToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::Arrow);
}

void ToolbarWidget::entityToolButtonClicked()
{
    uncheckAll();
    entityToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::Entity);
}

void ToolbarWidget::objectToolButtonClicked()
{
    uncheckAll();
    objectToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::Object);
}

void ToolbarWidget::handToolButtonClicked()
{
    uncheckAll();
    handToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::Hand);
}

void ToolbarWidget::zoomToolButtonClicked()
{
    uncheckAll();
    zoomToolButton->setChecked(true);
    m_mapWidget->setTool(Tool::Zoom);
}

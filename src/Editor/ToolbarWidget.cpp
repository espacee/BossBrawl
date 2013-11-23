#include "ToolbarWidget.hpp"
#include <QDebug>

namespace {

const char *images[TOOL_COUNT] {
    "res/img/GUI/pointer.png",
    "res/img/GUI/pen.png",
    "res/img/GUI/randomPen.png",
    "res/img/GUI/patternBrush.png",
    "res/img/GUI/eraser.png",
    "res/img/GUI/fillShape.png",
    "res/img/GUI/selectArea.png",
    "res/img/GUI/arrow.png",
    "res/img/GUI/entity.png",
    "res/img/GUI/object.png",
    "res/img/GUI/hand.png",
    "res/img/GUI/zoom.png"
};

} // End of anonymous namespace

ToolbarWidget::ToolbarWidget(QWidget *parent_) :
    QWidget(parent_)
{
    constexpr int toolButtonSize = 30;
    constexpr int toolButtonPadding = 2;
    constexpr int toolBarTopOffset = 44;
    constexpr int toolSeparatorSize = 10;
    auto getCateg = [](size_t index) {
        if (index < static_cast<size_t>(Tool::Arrow))
            return 0;
        else if (index < static_cast<size_t>(Tool::Hand))
            return 1;
        else
            return 2;
    };

    for (size_t i = 0; i < TOOL_COUNT; ++i) {
        QPushButton *&b = m_buttons[i];
        b = new QPushButton(QIcon(images[i]), "", this);
        b->setGeometry(toolButtonPadding,
                       toolBarTopOffset + (i * (toolButtonSize + toolButtonPadding)) + getCateg(i) * toolSeparatorSize,
                       toolButtonSize,
                       toolButtonSize
                      );
        b->setIconSize(QSize(toolButtonSize, toolButtonSize));
        b->setObjectName("toolButton");
        b->setCheckable(true);
        connect(b, &QPushButton::clicked, [ = ]() {
            for (auto b2 : m_buttons)
                b2->setChecked(false);

            b->setChecked(true);
            m_mapWidget->setTool(static_cast<Tool>(i));
        });
    }
}

void ToolbarWidget::doInitialClicks()
{
    m_buttons[static_cast<size_t>(Tool::Pen)]->click();
}

void ToolbarWidget::setMapWidget(MapWidget *mw)
{
    m_mapWidget = mw;
}

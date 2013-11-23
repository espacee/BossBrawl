#include "ToolbarWidget.hpp"
#include <QDebug>

ToolbarWidget::ToolbarWidget(QWidget *parent_) :
    QWidget(parent_)
{
    // Map an image file for each tool to be used as its button's icon
    const char *const images[TOOL_COUNT] {
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
    // Define some metrics for laying out buttons
    constexpr QSize btnsize(30, 30); // Button size
    constexpr int   padding = 2;     // Padding around buttons
    constexpr int   voffset = 44;    // Vertical offset from where buttons are laid out
    constexpr int   sep = 10;        // Separator space between button cagegories
    // Define the tool categories
    auto getCateg = [](size_t index) {
        if (index < static_cast<size_t>(Tool::Arrow))
            return 0;
        else if (index < static_cast<size_t>(Tool::Hand))
            return 1;
        else
            return 2;
    };
    // Create a button for each tool
    for (size_t i = 0; i < TOOL_COUNT; ++i) {
        QPushButton *&b = m_buttons[i];
        b = new QPushButton(QIcon(images[i]), "", this);
        b->setGeometry(padding,
                       voffset + (i * (btnsize.height() + padding)) + getCateg(i) * sep,
                       btnsize.width(),
                       btnsize.height()
                      );
        b->setIconSize(btnsize);
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

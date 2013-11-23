#ifndef TOOLBARWIDGET_HPP
#define TOOLBARWIDGET_HPP

#include <QWidget>
#include <QPushButton>
#include "tools.hpp"

class ToolbarWidget : public QWidget {
    Q_OBJECT
public:
    ToolbarWidget(QWidget *parent_);
    QPushButton *getButton(Tool t);
private:
    QPushButton *m_buttons[TOOL_COUNT];
};

#endif // TOOLBARWIDGET_HPP

#include "LayerItemWidget.hpp"
#include "ui_LayerSettingsDialog.h"

LayerItemWidget::LayerItemWidget(QWidget *parent_, TileMap &map) : QWidget(parent_),
    m_map(map)
{
    setObjectName("layer");
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(133, 70, 56));
    setPalette(pal);
    title = new QLabel(this);
    title->move(10, 0);
    title->setStyleSheet("color:white;");
    index = 0;
    propertiesButton = new QPushButton(">>", this);
    propertiesButton->setObjectName("button");
    dialog = new LayerSettingsDialog();
    connect(dialog->getUi()->nameEdit, SIGNAL(textChanged(QString)), this, SLOT(rename(QString)));
    connect(dialog->getUi()->widthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeWidth(int)));
    connect(dialog->getUi()->heightSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeHeigth(int)));
    connect(dialog->getUi()->xSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeX(int)));
    connect(dialog->getUi()->ySpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeY(int)));
    connect(dialog->getUi()->depthIndexSpinBox, SIGNAL(valueChanged(double)), this, SLOT(changeDepthIndex(double)));
    connect(propertiesButton, SIGNAL(clicked()), this, SLOT(activateDialog()));
}

void LayerItemWidget::setIndex(int i)
{
    index = i;
    dialog->getUi()->nameEdit->setText(QString::fromStdString(m_map[index].getName()));
    dialog->getUi()->widthSpinBox->setValue(m_map[index].getHLength());
    dialog->getUi()->heightSpinBox->setValue(m_map[index].getVLength());
    dialog->getUi()->xSpinBox->setValue(m_map[index].getPosition().x);
    dialog->getUi()->ySpinBox->setValue(m_map[index].getPosition().y);
    dialog->getUi()->depthIndexSpinBox->setValue(m_map[index].getDepthIndex());
}

void LayerItemWidget::setCurrent()
{
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(211, 83, 55));
    setPalette(pal);
}

void LayerItemWidget::unsetCurrent()
{
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(133, 70, 56));
    setPalette(pal);
}

void LayerItemWidget::mousePressEvent(QMouseEvent *)
{
    emit selected(index);
}

void LayerItemWidget::resizeEvent(QResizeEvent *)
{
    title->setFixedSize(width() - 30, height());
    propertiesButton->setGeometry(width() - 30, 0, 30, height());
}

void LayerItemWidget::rename(QString new_name)
{
    m_map[index].setName(new_name.toStdString());
    title->setText(new_name);
}

void LayerItemWidget::changeWidth(int value)
{
    m_map[index].resize(value, m_map[index].getVLength());
}

void LayerItemWidget::changeHeigth(int value)
{
    m_map[index].resize(m_map[index].getHLength(), value);
}

void LayerItemWidget::changeX(int value)
{
    m_map[index].setPosition(value, m_map[index].getPosition().y);
}

void LayerItemWidget::changeY(int value)
{
    m_map[index].setPosition(m_map[index].getPosition().x, value);
}

void LayerItemWidget::changeDepthIndex(double depthIndex)
{
    m_map[index].setDepthIndex(depthIndex);
}

void LayerItemWidget::changeGridColor(QColor color)
{
    m_map[index].setGridColor(sf::Color(color.red(), color.green(), color.blue()));
}
void LayerItemWidget::clearLayer()
{
    m_map[index].fill(0);
}

void LayerItemWidget::activateDialog()
{
    dialog->setModal(true);
    dialog->show();
    dialog->activateWindow();
}


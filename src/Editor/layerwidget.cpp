#include "layerwidget.h"
#include "ui_layersettings.h"

LayerWidget::LayerWidget(QWidget *parent_, TileMap &map) : QWidget(parent_),
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

void LayerWidget::setIndex(int i)
{
    index = i;

    dialog->getUi()->nameEdit->setText(QString::fromStdString(m_map[index].getName()));
    dialog->getUi()->widthSpinBox->setValue(m_map[index].getHLength());
    dialog->getUi()->heightSpinBox->setValue(m_map[index].getVLength());
    dialog->getUi()->xSpinBox->setValue(m_map[index].getPosition().x);
    dialog->getUi()->ySpinBox->setValue(m_map[index].getPosition().y);
    dialog->getUi()->depthIndexSpinBox->setValue(m_map[index].getDepthIndex());
}

void LayerWidget::setCurrent()
{
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(211, 83, 55));
    setPalette(pal);
}

void LayerWidget::unsetCurrent()
{
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(133, 70, 56));
    setPalette(pal);
}

void LayerWidget::mousePressEvent(QMouseEvent *)
{
    emit selected(index);
}

void LayerWidget::resizeEvent(QResizeEvent *)
{
    title->setFixedSize(width() - 30, height());
    propertiesButton->setGeometry(width() - 30, 0, 30, height());
}

void LayerWidget::rename(QString new_name)
{
    m_map[index].setName(new_name.toStdString());
    title->setText(new_name);
}

void LayerWidget::changeWidth(int value)
{
    m_map[index].resize(value, m_map[index].getVLength());
}

void LayerWidget::changeHeigth(int value)
{
    m_map[index].resize(m_map[index].getHLength(), value);
}

void LayerWidget::changeX(int value)
{
    m_map[index].setPosition(value, m_map[index].getPosition().y);
}

void LayerWidget::changeY(int value)
{
    m_map[index].setPosition(m_map[index].getPosition().x, value);
}

void LayerWidget::changeDepthIndex(double depthIndex)
{
    m_map[index].setDepthIndex(depthIndex);
}

void LayerWidget::changeGridColor(QColor color)
{
    m_map[index].setGridColor(sf::Color(color.red(), color.green(), color.blue()));
}
void LayerWidget::clearLayer()
{
    m_map[index].fill(0);
}

void LayerWidget::activateDialog()
{
    dialog->setModal(true);
    dialog->show();
    dialog->activateWindow();
}


#include "Editor/layerwidget.h"
#include "ui_layersettings.h"

LayerWidget::LayerWidget(QString new_name, QWidget *parent, TileMap *mapP) : QWidget(parent)
{
    map = mapP;
    setObjectName("layer");

    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(200, 200, 200));
    setPalette(pal);

    name = new_name;
    title = new QLabel(name, this);
    title->move(5, 5);
    index = 0;

    propertiesButton = new QPushButton(">>", this);
    propertiesButton->setGeometry(width() - 20, 0, 20, height());
    propertiesButton->setObjectName("button");

    dialog = new LayerSettings();

    connect(dialog->getUi()->nameEdit, SIGNAL(textChanged(QString)), this, SLOT(rename(QString)));
    connect(dialog->getUi()->widthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeWidth(int)));
    connect(dialog->getUi()->heightSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeHeigth(int)));
    connect(dialog->getUi()->xSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeX(int)));
    connect(dialog->getUi()->ySpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeY(int)));
    connect(dialog->getUi()->depthIndexSpinBox, SIGNAL(valueChanged(double)), this, SLOT(changeDepthIndex(double)));
    connect(dialog->getUi()->gridCheckBox, SIGNAL(toggled(bool)), this, SLOT(changeGridEnabled(bool)));
    connect(dialog->getUi()->clearlayer, SIGNAL(clicked()), this, SLOT(clearLayer()));

    connect(propertiesButton, SIGNAL(clicked()), dialog, SLOT(exec()));
}

void LayerWidget::setIndex(int i)
{
    index = i;

    dialog->getUi()->nameEdit->setText(name);
    dialog->getUi()->widthSpinBox->setValue(map->getLayer(index)->getHLength());
    dialog->getUi()->heightSpinBox->setValue(map->getLayer(index)->getVLength());
    dialog->getUi()->xSpinBox->setValue(map->getLayer(index)->getPosition().x);
    dialog->getUi()->ySpinBox->setValue(map->getLayer(index)->getPosition().y);
    dialog->getUi()->depthIndexSpinBox->setValue(map->getLayer(index)->getDepthIndex());
    dialog->getUi()->gridCheckBox->setChecked(map->getLayer(index)->gridEnabled());
}

void LayerWidget::setCurrent()
{
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(150, 180, 255));
    setPalette(pal);
}

void LayerWidget::unsetCurrent()
{
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(200, 200, 200));
    setPalette(pal);
}

void LayerWidget::mousePressEvent(QMouseEvent *)
{
    emit selected(index);
}

void LayerWidget::resizeEvent(QResizeEvent *)
{

    propertiesButton->setGeometry(width() - 20, 0, 20, height());
}

void LayerWidget::rename(QString new_name)
{
    name = new_name;
    title->setText(name);
    title->setFixedWidth(width() - 20);
}

void LayerWidget::changeWidth(int width)
{
    map->getLayer(index)->resize(width, map->getLayer(index)->getVLength());
}

void LayerWidget::changeHeigth(int height)
{
    map->getLayer(index)->resize(map->getLayer(index)->getHLength(), height);
}

void LayerWidget::changeX(int x)
{
    map->getLayer(index)->setPosition(x, map->getLayer(index)->getPosition().y);
}

void LayerWidget::changeY(int y)
{
    map->getLayer(index)->setPosition(map->getLayer(index)->getPosition().x, y);
}

void LayerWidget::changeDepthIndex(double depthIndex)
{
    map->getLayer(index)->setDepthIndex(depthIndex);
}

void LayerWidget::changeGridEnabled(bool enabled)
{
    map->getLayer(index)->setGridEnabled(enabled);
}

void LayerWidget::changeGridColor(QColor color)
{
    map->getLayer(index)->setGridColor(sf::Color(color.red(), color.green(), color.blue()));
}
void LayerWidget::clearLayer()
{
    map->getLayer(index)->fill(0);
}


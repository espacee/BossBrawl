#include "Editor/layerwidget.h"
#include "ui_layersettings.h"

LayerWidget::LayerWidget(QWidget *parent, TileMap *mapP) : QWidget(parent)
{
    map = mapP;
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

    dialog = new LayerSettings();

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

    dialog->getUi()->nameEdit->setText(QString::fromStdString((*map)[index]->getName()));
    dialog->getUi()->widthSpinBox->setValue((*map)[index]->getHLength());
    dialog->getUi()->heightSpinBox->setValue((*map)[index]->getVLength());
    dialog->getUi()->xSpinBox->setValue((*map)[index]->getPosition().x);
    dialog->getUi()->ySpinBox->setValue((*map)[index]->getPosition().y);
    dialog->getUi()->depthIndexSpinBox->setValue((*map)[index]->getDepthIndex());
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
    (*map)[index]->setName(new_name.toStdString());
    title->setText(new_name);
}

void LayerWidget::changeWidth(int width)
{
    (*map)[index]->resize(width, (*map)[index]->getVLength());
}

void LayerWidget::changeHeigth(int height)
{
    (*map)[index]->resize((*map)[index]->getHLength(), height);
}

void LayerWidget::changeX(int x)
{
    (*map)[index]->setPosition(x, (*map)[index]->getPosition().y);
}

void LayerWidget::changeY(int y)
{
    (*map)[index]->setPosition((*map)[index]->getPosition().x, y);
}

void LayerWidget::changeDepthIndex(double depthIndex)
{
    (*map)[index]->setDepthIndex(depthIndex);
}

void LayerWidget::changeGridColor(QColor color)
{
    (*map)[index]->setGridColor(sf::Color(color.red(), color.green(), color.blue()));
}
void LayerWidget::clearLayer()
{
    (*map)[index]->fill(0);
}

void LayerWidget::activateDialog()
{
    dialog->setModal(true);
    dialog->show();
    dialog->activateWindow();
}


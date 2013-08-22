#include "layersettings.h"
#include "ui_layersettings.h"
#include <QString>

LayerSettings::LayerSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LayerSettings)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Tool);
    layout()->setSizeConstraint(QLayout::SetFixedSize);
}

Ui::LayerSettings *LayerSettings::getUi()
{
    return ui;
}

LayerSettings::~LayerSettings()
{
    delete ui;
}

void LayerSettings::on_OKButton_clicked()
{
    accept();
}

#include "layersettings.h"
#include "ui_layersettings.h"
#include <QString>

LayerSettings::LayerSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LayerSettings)
{
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Tool);
    ui->setupUi(this);
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

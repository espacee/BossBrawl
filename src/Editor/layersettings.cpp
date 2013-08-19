#include "layersettings.h"
#include "ui_layersettings.h"

LayerSettings::LayerSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LayerSettings)
{
    ui->setupUi(this);
}

LayerSettings::~LayerSettings()
{
    delete ui;
}

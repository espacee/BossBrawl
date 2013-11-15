#include "LayerSettingsDialog.hpp"
#include "ui_layersettings.h"
#include <QString>

LayerSettingsDialog::LayerSettingsDialog(QWidget *parent_) :
    QDialog(parent_),
    ui(new Ui::LayerSettings)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Tool);
    layout()->setSizeConstraint(QLayout::SetFixedSize);
}

Ui::LayerSettings *LayerSettingsDialog::getUi()
{
    return ui;
}

LayerSettingsDialog::~LayerSettingsDialog()
{
    delete ui;
}

void LayerSettingsDialog::on_OKButton_clicked()
{
    accept();
}

#include "layersettings.h"
#include "ui_layersettings.h"
#include <QString>

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

void LayerSettings::loadLayerSettings(int setindex, QString setname, int setheight, int setwidth, int setposX, int setposY, float setdepthindex, bool setgridenabled )
{
index = setindex;
name = setname;
height = setheight;
width = setwidth;
posX = setposX;
posY = setposY;
depthindex = setdepthindex;
gridenabled = setgridenabled;

ui->nameedit->setText(name);
ui->heightedit->setValue(height);
ui->widthedit->setValue(width);
ui->xedit->setValue(posX);
ui->yedit->setValue(posY);
ui->depthindexedit->setValue(depthindex);
ui->gridcheckbox->setChecked(gridenabled);


}
void LayerSettings::saveLayerSettings()
{
name = ui->nameedit->text();
height = ui->heightedit->value();
width = ui->widthedit->value();
posX = ui->xedit->value();
posY = ui->yedit->value();
depthindex = ui->depthindexedit->value();
gridenabled = ui->gridcheckbox->isChecked();

map->setLayerPosition(index, posX, posY);
map->resizeLayer(index, height, width);
map->setLayerGridEnabled(index, gridenabled);
map->setLayerDepthIndex(index, depthindex);



}

void LayerSettings::on_buttonBox_accepted()
{
saveLayerSettings();

}

#ifndef LAYERSETTINGS_H
#define LAYERSETTINGS_H

#include <QDialog>
#include "Map/TileMap.hpp"

namespace Ui {
class LayerSettings;
}

class LayerSettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit LayerSettings( QWidget *parent = 0);
    ~LayerSettings();

    void loadLayerSettings(int index, QString name, int height, int width, int posX, int posY, float depthindex, bool gridenabled );
    void saveLayerSettings();


    
private slots:
  void on_buttonBox_accepted();

private:
    Ui::LayerSettings *ui;
    TileMap* map;


    QString name;
    int index, height, width, posX, posY;
    float depthindex;
    bool gridenabled;
};

#endif // LAYERSETTINGS_H

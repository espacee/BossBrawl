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

    Ui::LayerSettings* getUi();

private slots:

    void on_OKButton_clicked();

private:
    Ui::LayerSettings *ui;
    TileMap* map;
};

#endif // LAYERSETTINGS_H

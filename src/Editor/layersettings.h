#ifndef LAYERSETTINGS_H
#define LAYERSETTINGS_H

#include <QDialog>

namespace Ui {
class LayerSettings;
}

class LayerSettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit LayerSettings(QWidget *parent = 0);
    ~LayerSettings();
    
private:
    Ui::LayerSettings *ui;
};

#endif // LAYERSETTINGS_H

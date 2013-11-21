#ifndef LAYERSETTINGSDIALOG_HPP
#define LAYERSETTINGSDIALOG_HPP

#include <QDialog>

namespace Ui {
class LayerSettings;
}

class LayerSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LayerSettingsDialog(QWidget *parent = 0);
    ~LayerSettingsDialog();

    Ui::LayerSettings* getUi();

private slots:

    void on_OKButton_clicked();

private:
    Ui::LayerSettings *ui;
};

#endif // LAYERSETTINGSDIALOG_HPP

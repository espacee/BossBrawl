#ifndef LAYERITEMWIDGET_HPP
#define LAYERITEMWIDGET_HPP

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QResizeEvent>

#include "LayerSettingsDialog.hpp"
#include "Map/TileMap.hpp"

class LayerItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LayerItemWidget(QWidget *parent);
    void setIndex(int i);
    void setCurrent();
    void unsetCurrent();

signals:
    void selected(int);

public slots:
    void rename(QString new_name);
    void changeWidth(int value);
    void changeHeigth(int value);
    void changeX(int value);
    void changeY(int value);
    void changeDepthIndex(double depthIndex);
    void changeGridColor(QColor color);
    void clearLayer();
    void activateDialog();

protected:
    void mousePressEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);

private:
    QLabel* title;
    QPushButton* propertiesButton;
    LayerSettingsDialog* dialog;

    int index;
};

#endif // LAYERITEMWIDGET_HPP

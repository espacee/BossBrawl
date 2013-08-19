#ifndef LAYERWIDGET_H
#define LAYERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QResizeEvent>

#include "Map/TileMap.hpp"

class LayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LayerWidget(QString new_name, QWidget *parent, TileMap* mapP);
    void setIndex(int i);
    void setCurrent();
    void unsetCurrent();
    void rename(QString new_name);
    void propertiesButtonClicked();

signals:
    void selected(int);

public slots:

protected:
    void mousePressEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);
    
private:
    TileMap* map;

    QLabel* title;
    QString name;
    QPushButton* propertiesButton;

    int index;
};

#endif // LAYERWIDGET_H

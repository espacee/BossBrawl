#ifndef LAYERWIDGET_H
#define LAYERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QResizeEvent>

class LayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LayerWidget(QWidget *parent = 0);
    
signals:
    
public slots:

    
private:
    QPushButton* btn;
};

#endif // LAYERWIDGET_H

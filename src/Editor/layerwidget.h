#ifndef LAYERWIDGET_H
#define LAYERWIDGET_H

#include <QWidget>
#include <QLabel>

class LayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LayerWidget(QString new_name, QWidget *parent);
    void setIndex(int i);
    void setCurrent();
    void unsetCurrent();
    void rename(QString new_name);

    bool isCurrentSet();

signals:
    void selected(int);

public slots:

protected:
    void mousePressEvent(QMouseEvent *);
    
private:
    QLabel* title;
    QString name;
    int index;
    bool currentSet;
};

#endif // LAYERWIDGET_H

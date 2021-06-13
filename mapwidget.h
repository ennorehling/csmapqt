#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QOpenGLWidget>

class MapWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    MapWidget() {
        loadImages();
    };
    MapWidget(QWidget *parent) : QOpenGLWidget(parent) {
        loadImages();
    };

private:
    void paintEvent(QPaintEvent *event) override;

protected:
    void loadImages();

    QImage ocean;
};

#endif // MAPWIDGET_H

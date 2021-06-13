#include "mapwidget.h"

#include <QPainter>

void MapWidget::loadImages()
{
    ocean.load(":/images/res/terrains/ocean.gif");
}

void MapWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    for (int x = 0; x != 10; ++x) {
        for (int y = 0; y != 10; ++y) {
            int px = ocean.width() / 2 * (2 * x + (y & 1));
            int py = y * ocean.height() * 3 / 4;
            painter.drawImage(QPoint(px, py), ocean);
        }
    }
    painter.drawImage(QPoint(ocean.width(), 0), ocean);
    painter.drawImage(QPoint(ocean.width() / 2, ocean.height() * 3/4), ocean);
    painter.end();
}


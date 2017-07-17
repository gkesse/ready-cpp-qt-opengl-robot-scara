#include "GGraphicsPixmapItem.h"
#include <QApplication>

GGraphicsPixmapItem::GGraphicsPixmapItem(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent) {
    createObjects();
    createConnexions();
}

GGraphicsPixmapItem::~GGraphicsPixmapItem() {

}

void GGraphicsPixmapItem::createObjects() {
    setCacheMode(DeviceCoordinateCache);
}

void GGraphicsPixmapItem::createConnexions() {

}


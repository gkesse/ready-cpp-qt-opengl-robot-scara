#include "GGraphicsView.h"

GGraphicsView::GGraphicsView(QWidget *parent) :
    QGraphicsView(parent) {
    createObjects();
    createConnexions();
}

GGraphicsView::~GGraphicsView() {

}

void GGraphicsView::createObjects() {

}

void GGraphicsView::createConnexions() {

}

void GGraphicsView::resizeEvent(QResizeEvent* event) {
    QGraphicsView::resizeEvent(event);
    fitInView(sceneRect(), Qt::KeepAspectRatio);
}

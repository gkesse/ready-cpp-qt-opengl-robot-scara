#include "GGraphicsView.h"
#include "GGraphicsScene.h"

GGraphicsView::GGraphicsView(QWidget *parent) :
    QGraphicsView(parent) {
    createObjects();
    createConnexions();
}

GGraphicsView::~GGraphicsView() {

}

void GGraphicsView::createObjects() {
    GGraphicsScene* m_scene = new GGraphicsScene;
    setScene(m_scene);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setCacheMode(QGraphicsView::CacheBackground);
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void GGraphicsView::createConnexions() {

}

void GGraphicsView::resizeEvent(QResizeEvent* event) {
    QGraphicsView::resizeEvent(event);
    fitInView(sceneRect(), Qt::KeepAspectRatio);
}

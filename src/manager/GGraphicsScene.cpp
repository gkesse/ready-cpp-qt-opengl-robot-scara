#include "GGraphicsScene.h"
#include "GGraphicsPixmapItem.h"
#include "GGraphicsWidget.h"
#include <QApplication>
#include <QGraphicsRectItem>

GGraphicsScene::GGraphicsScene(QObject* parent) :
    QGraphicsScene(parent) {
    createObjects();
    createConnexions();
}

GGraphicsScene::~GGraphicsScene() {

}

void GGraphicsScene::createObjects() {
    setSceneRect(-350, -350, 700, 700);

    QPixmap m_pixmap("../../src/res/img/kinetic.png");
    int m_pixmapW = m_pixmap.width();
    int m_pixmapH = m_pixmap.height();
    double m_x = -m_pixmapW/2.0;
    double m_y = -m_pixmapH/2.0;

    for(int i = 0; i < 64; i++) {
        GGraphicsPixmapItem* m_pixmapItem = new GGraphicsPixmapItem;
        m_pixmapItem->setPixmap(m_pixmap);
        m_pixmapItem->setOffset(m_x, m_y);
        m_pixmapItem->setZValue(i);

        m_pixmapItems.push_back(m_pixmapItem);

        addItem(m_pixmapItem);
    }

    QGraphicsRectItem* m_rectItem = new QGraphicsRectItem;
    m_rectItem->setTransform(QTransform::fromScale(0.75, 0.75), true);
    m_rectItem->setPos(200, 200);
    m_rectItem->setZValue(65);

    GGraphicsWidget* m_ellipseButton = new GGraphicsWidget(m_rectItem);
    m_ellipseButton->setPixmap(QPixmap(":/img/ellipse.png"));
    m_ellipseButton->setPos(-100, -100);

    addItem(m_rectItem);
}

void GGraphicsScene::createConnexions() {

}

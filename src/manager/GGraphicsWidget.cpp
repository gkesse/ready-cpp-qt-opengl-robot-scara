#include "GGraphicsWidget.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

GGraphicsWidget::GGraphicsWidget(QGraphicsItem *parent) :
    QGraphicsWidget(parent) {
    createObjects();
    createConnexions();
}

GGraphicsWidget::~GGraphicsWidget() {

}

void GGraphicsWidget::createObjects() {
    setAcceptHoverEvents(true);
    setCacheMode(DeviceCoordinateCache);
}

void GGraphicsWidget::createConnexions() {

}

void GGraphicsWidget::setPixmap(const QPixmap& pixmap) {
    m_pixmap = pixmap;
}

QRectF GGraphicsWidget::boundingRect() const {
    return QRectF(-65, -65, 130, 130);
}

QPainterPath GGraphicsWidget::shape() const {
    QPainterPath m_path;
    m_path.addEllipse(boundingRect());
    return m_path;
}

void GGraphicsWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    bool down = option->state & QStyle::State_Sunken;
    QRectF r = boundingRect();
    QLinearGradient grad(r.topLeft(), r.bottomRight());
    grad.setColorAt(down ? 1 : 0, option->state & QStyle::State_MouseOver ? Qt::white : Qt::lightGray);
    grad.setColorAt(down ? 0 : 1, Qt::darkGray);
    painter->setPen(Qt::darkGray);
    painter->setBrush(grad);
    painter->drawEllipse(r);
    QLinearGradient grad2(r.topLeft(), r.bottomRight());
    grad.setColorAt(down ? 1 : 0, Qt::darkGray);
    grad.setColorAt(down ? 0 : 1, Qt::lightGray);
    painter->setPen(Qt::NoPen);
    painter->setBrush(grad);
    if (down)
        painter->translate(2, 2);
    painter->drawEllipse(r.adjusted(5, 5, -5, -5));

    int m_pixmapW = m_pixmap.width();
    int m_pixmapH = m_pixmap.height();
    int m_x = -m_pixmapW/2.0;
    int m_y = -m_pixmapH/2.0;

    painter->drawPixmap(-m_x, -m_y, m_pixmap);
}

void GGraphicsWidget::mousePressEvent(QGraphicsSceneMouseEvent *event) {

}

void GGraphicsWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

}

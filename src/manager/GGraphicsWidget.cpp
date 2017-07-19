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
    setCursor(Qt::PointingHandCursor);
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
    m_path.addRect(boundingRect());
    return m_path;
}

void GGraphicsWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    bool m_mouseOver = option->state & QStyle::State_MouseOver;
    bool m_shunken = option->state & QStyle::State_Sunken;
    QRectF m_rect = boundingRect();

    QColor m_bgColor = QColor("#051039");
    QColor m_color = m_bgColor;
    m_color =  m_mouseOver ? QColor("#ffffff") : m_bgColor;
    m_color =  m_shunken ? m_bgColor : m_color;

    painter->setPen(Qt::NoPen);
    painter->setBrush(m_color);
    painter->drawEllipse(m_rect);

    int m_x = -m_pixmap.width()/2;
    int m_y = -m_pixmap.height()/2;
    painter->drawPixmap(m_x, m_y, m_pixmap);
}

void GGraphicsWidget::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
    update();
    emit emitPressed();
}

void GGraphicsWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
    update();
}


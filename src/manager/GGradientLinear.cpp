#include "GGradientLinear.h"
#include <QPainter>

#include "GMessageView.h"

GGradientLinear::GGradientLinear(QWidget *parent) :
    QFrame(parent){
    createObjects();
    createConnexions();
}

GGradientLinear::~GGradientLinear() {
    
}

void GGradientLinear::createObjects() {

}

void GGradientLinear::createConnexions() {
    
}

void GGradientLinear::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter m_painter(this);
    m_painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
    QRect m_rect = contentsRect();
    QLinearGradient m_grad(m_rect.topLeft(), m_rect.bottomRight());
    m_grad.setColorAt(0, "navy");
    m_grad.setColorAt(1, "white");
    m_painter.setPen(Qt::darkGray);
    m_painter.setBrush(m_grad);
    m_painter.drawEllipse(m_rect);
}

QSize GGradientLinear::sizeHint() const {
    return QSize(100, 100);
}

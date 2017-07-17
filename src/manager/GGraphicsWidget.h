#ifndef _GGraphicsWidget_
#define _GGraphicsWidget_

#include <QGraphicsWidget>

class GGraphicsWidget : public QGraphicsWidget {
    Q_OBJECT

public:
    GGraphicsWidget(QGraphicsItem* parent = 0);
    ~GGraphicsWidget();

private:
    void createObjects();
    void createConnexions();

public:
    void setPixmap(const QPixmap& pixmap);

protected:
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QPixmap m_pixmap;
};

#endif

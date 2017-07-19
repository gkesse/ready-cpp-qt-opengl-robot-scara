#ifndef _GGraphicsPixmapItem_
#define _GGraphicsPixmapItem_

#include <QGraphicsPixmapItem>

class GGraphicsPixmapItem : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    GGraphicsPixmapItem(QGraphicsItem* parent = 0);
    ~GGraphicsPixmapItem();

private:
    void createObjects();
    void createConnexions();

};

#endif

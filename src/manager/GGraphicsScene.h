#ifndef _GGraphicsScene_
#define _GGraphicsScene_

#include "GGraphicsPixmapItem.h"
#include <QGraphicsScene>

class GGraphicsScene : public QGraphicsScene {
    Q_OBJECT

public:
    GGraphicsScene(QObject* parent = 0);
    ~GGraphicsScene();

private:
    void createObjects();
    void createConnexions();

private:
    QList<GGraphicsPixmapItem*> m_pixmapItems;
};

#endif

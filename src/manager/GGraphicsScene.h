#ifndef _GGraphicsScene_
#define _GGraphicsScene_

#include "GGraphicsPixmapItem.h"
#include <QGraphicsScene>
#include <QState>
#include <QStateMachine>
#include <QParallelAnimationGroup>
#include <QGraphicsWidget>

class GGraphicsScene : public QGraphicsScene {
    Q_OBJECT

public:
    GGraphicsScene(QObject* parent = 0);
    ~GGraphicsScene();

private:
    void createObjects();
    void createConnexions();
    void createTransitions();
    void createAnimations();

private:
    QList<GGraphicsPixmapItem*> m_pixmapList;
    QMap<QString, QState*> m_stateMap;
    QMap<QString, QGraphicsWidget*> m_buttonMap;
    QParallelAnimationGroup* m_group;
};

#endif

#include "GGraphicsScene.h"
#include "GGraphicsPixmapItem.h"
#include "GGraphicsWidget.h"
#include "GJson.h"
#include <QApplication>
#include <QGraphicsRectItem>
#include <QtMath>
#include <QStateMachine>
#include <QSignalTransition>
#include <QAbstractTransition>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QTimer>

#include "GMessageView.h"

GGraphicsScene::GGraphicsScene(QObject* parent) :
    QGraphicsScene(parent) {
    createObjects();
    createConnexions();
    createAnimations();
    createTransitions();
    //startStateMachine();
}

GGraphicsScene::~GGraphicsScene() {

}

void GGraphicsScene::createObjects() {
    setSceneRect(-350, -350, 700, 700);
    GJson::Instance()->load(":/json/GraphicsView.json");
    GArrayMap m_dataArray;

    QPixmap m_pixmap(":/img/kinetic.png");
    int m_pixmapW = m_pixmap.width();
    int m_pixmapH = m_pixmap.height();
    double m_x = -m_pixmapW/2.0;
    double m_y = -m_pixmapH/2.0;

    for(int i = 0; i < 64; i++) {
        GGraphicsPixmapItem* m_pixmapItem = new GGraphicsPixmapItem;
        m_pixmapItem->setPixmap(m_pixmap);
        m_pixmapItem->setOffset(m_x, m_y);
        m_pixmapItem->setZValue(i);
        m_pixmapList.push_back(m_pixmapItem);
        addItem(m_pixmapItem);
    }


    QGraphicsRectItem* m_rectItem = new QGraphicsRectItem;
    m_rectItem->setTransform(QTransform::fromScale(0.75, 0.75), true);
    m_rectItem->setPos(200, 200);
    m_rectItem->setZValue(65);

    m_dataArray = GJson::Instance()->getArray("buttons");

    for(int i = 0; i < m_dataArray.size(); i++) {
        QVariantMap m_dataMap = m_dataArray.at(i);
        QString m_name = m_dataMap.value("name").toString();
        QString m_img = m_dataMap.value("img").toString();
        int m_x = m_dataMap.value("x").toInt();
        int m_y = m_dataMap.value("y").toInt();
        GGraphicsWidget* m_button = new GGraphicsWidget(m_rectItem);
        m_button->setPixmap(QPixmap(m_img));
        m_button->setPos(m_x, m_y);
        m_buttonMap.insert(m_name, m_button);
    }

    addItem(m_rectItem);

    m_dataArray = GJson::Instance()->getArray("states");
    QState* m_rootState = new QState;

    for(int i = 0; i < m_dataArray.size(); i++) {
        QVariantMap m_dataMap = m_dataArray.at(i);
        QString m_name = m_dataMap.value("name").toString();
        QState* m_state = new QState(m_rootState);
        m_stateMap.insert(m_name, m_state);
    }

    m_stateMap.insert("root", m_rootState);

    for(int i = 0; i < m_pixmapList.size(); i++) {
        GGraphicsPixmapItem* m_pixmapItem = m_pixmapList.at(i);

        for(int j = 0; j < m_stateMap.size(); j++) {
            QString m_name = m_stateMap.keys().at(j);

            if(m_name == "ellipse") {
                QState* m_state = m_stateMap.value(m_name);
                double m_x = qCos((i / 63.0) * 6.28) * 250;
                double m_y = qSin((i / 63.0) * 6.28) * 250;
                m_state->assignProperty(m_pixmapItem, "pos", QPointF(m_x, m_y));
            }
            if(m_name == "figure8") {
                QState* m_state = m_stateMap.value(m_name);
                double m_x = qSin((i / 63.0) * 6.28) * 250;
                double m_y = qSin(((i * 2)/63.0) * 6.28) * 250;
                m_state->assignProperty(m_pixmapItem, "pos", QPointF(m_x, m_y));
            }
            if(m_name == "random") {
                QState* m_state = m_stateMap.value(m_name);
                double m_x = -250 + qrand() % 500;
                double m_y = -250 + qrand() % 500;
                m_state->assignProperty(m_pixmapItem, "pos", QPointF(m_x, m_y));
            }
            if(m_name == "tile") {
                QState* m_state = m_stateMap.value(m_name);
                double m_x = ((i % 8) - 4) * m_pixmapW + m_pixmapW / 2;
                double m_y = ((i / 8) - 4) * m_pixmapH + m_pixmapH / 2;
                m_state->assignProperty(m_pixmapItem, "pos", QPointF(m_x, m_y));
            }
            if(m_name == "centered") {
                QState* m_state = m_stateMap.value(m_name);
                double m_x = 0;
                double m_y = 0;
                m_state->assignProperty(m_pixmapItem, "pos", QPointF(m_x, m_y));
            }
        }
    }

    QStateMachine* m_stateMachine = new QStateMachine;
    m_stateMachine->addState(m_rootState);
    m_stateMachine->setInitialState(m_rootState);
    m_rootState->setInitialState(m_stateMap.value("centered"));
    m_stateMachine->start();

    m_group = new QParallelAnimationGroup;
}

void GGraphicsScene::createConnexions() {

}

void GGraphicsScene::createTransitions() {
    QAbstractTransition* m_trans;

    QTimer* m_timer = new QTimer(this);
    m_timer->setSingleShot(true);
    m_trans = m_stateMap.value("root")->addTransition(m_timer, SIGNAL(timeout()), m_stateMap.value("ellipse"));
    m_trans->addAnimation(m_group);
    m_timer->start(125);

    m_trans = m_stateMap.value("root")->addTransition(m_buttonMap.value("ellipse"), SIGNAL(emitPressed()), m_stateMap.value("ellipse"));
    m_trans->addAnimation(m_group);

    m_trans = m_stateMap.value("root")->addTransition(m_buttonMap.value("figure8"), SIGNAL(emitPressed()), m_stateMap.value("figure8"));
    m_trans->addAnimation(m_group);

    m_trans = m_stateMap.value("root")->addTransition(m_buttonMap.value("random"), SIGNAL(emitPressed()), m_stateMap.value("random"));
    m_trans->addAnimation(m_group);

    m_trans = m_stateMap.value("root")->addTransition(m_buttonMap.value("tile"), SIGNAL(emitPressed()), m_stateMap.value("tile"));
    m_trans->addAnimation(m_group);

    m_trans = m_stateMap.value("root")->addTransition(m_buttonMap.value("centered"), SIGNAL(emitPressed()), m_stateMap.value("centered"));
    m_trans->addAnimation(m_group);
}

void GGraphicsScene::createAnimations() {
    for (int i = 0; i < m_pixmapList.size(); ++i) {
        QPropertyAnimation* m_anim = new QPropertyAnimation(m_pixmapList.at(i), "pos");
        m_anim->setDuration(750 + i * 25);
        m_anim->setEasingCurve(QEasingCurve::InOutBack);
        m_group->addAnimation(m_anim);
    }
}


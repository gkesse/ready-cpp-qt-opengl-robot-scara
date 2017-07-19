#ifndef _GGraphicsViewV_
#define _GGraphicsViewV_

#include <QWidget>
#include <QFrame>
#include <QGraphicsScene>

namespace Ui {
class GGraphicsViewV;
}

class GGraphicsViewV : public QFrame {
    Q_OBJECT

public:
    GGraphicsViewV(QWidget* parent = 0);
    ~GGraphicsViewV();

private:
    void createObjects();
    void createConnexions();

private:
    Ui::GGraphicsViewV* ui;
};

#endif

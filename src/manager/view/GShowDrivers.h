#ifndef _GShowDrivers_
#define _GShowDrivers_

#include <QWidget>
#include <QFrame>

namespace Ui {
class GShowDrivers;
}

class GShowDrivers : public QFrame {
    Q_OBJECT

public:
    GShowDrivers(QWidget* parent = 0);
    ~GShowDrivers();

private:
    void createObjects();
    void createConnexions();

public slots:
    void slotCreateClicked();

private:
    Ui::GShowDrivers* ui;
};

#endif

#ifndef _GMenu_
#define _GMenu_

#include <QWidget>
#include <QFrame>

namespace Ui {
class GMenu;
}

class GMenu : public QFrame {
    Q_OBJECT

public:
    GMenu(QWidget* parent = 0);
    ~GMenu();

private:
    void createObjects();
    void createConnexions();

private:
    Ui::GMenu* ui;
};

#endif

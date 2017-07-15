#ifndef _GMenu_
#define _GMenu_

#include <QWidget>
#include <QFrame>
#include <QSignalMapper>

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

signals:
    void emitMenuClicked(const int&);

private:
    Ui::GMenu* ui;
    QSignalMapper *m_signalMapper;
};

#endif

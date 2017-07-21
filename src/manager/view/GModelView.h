#ifndef _GModelView_
#define _GModelView_

#include <QWidget>
#include <QFrame>

namespace Ui {
class GModelView;
}

class GModelView : public QFrame {
    Q_OBJECT

public:
    GModelView(QWidget* parent = 0);
    ~GModelView();

private:
    void createObjects();
    void createConnexions();

private:
    Ui::GModelView* ui;
};

#endif

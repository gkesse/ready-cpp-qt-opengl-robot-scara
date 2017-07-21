#ifndef _GGradientView_
#define _GGradientView_

#include <QWidget>
#include <QFrame>

namespace Ui {
class GGradientView;
}

class GGradientView : public QFrame {
    Q_OBJECT

public:
    GGradientView(QWidget* parent = 0);
    ~GGradientView();

private:
    void createObjects();
    void createConnexions();

private:
    Ui::GGradientView* ui;
};

#endif

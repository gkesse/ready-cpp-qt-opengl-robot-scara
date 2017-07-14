#ifndef _GMessageView_
#define _GMessageView_

#include <QWidget>

namespace Ui {
class GMessageView;
}

class GMessageView : public QWidget {
    Q_OBJECT

private:
    GMessageView();

public:
    ~GMessageView();

public:
    static GMessageView* Instance();

private:
    void createObjects();
    void createConnexions();

private:
    void setPosition();

public:
    void show(const QString& data);

public slots:
    void slotClearClicked();

private:
    static GMessageView* m_instance;
    Ui::GMessageView* ui;
};

#endif

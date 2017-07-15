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
    void showData(const QString& data, const QString& name = "");
    void showData(const char* data, const QString& name = "");
    void showData(const bool& data, const QString& name = "");
    void showData(const int& data, const QString& name = "");
    void showData(const double& data, const QString& name = "");
    void showData(const QStringList& data, const QString& name = "");

public slots:
    void slotClearClicked();

private:
    static GMessageView* m_instance;
    Ui::GMessageView* ui;
};

#endif

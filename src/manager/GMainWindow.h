#ifndef _GMAINWINDOW_
#define _GMAINWINDOW_

#include <QWidget>

namespace Ui {
class GMainWindow;
}

class GMainWindow : public QWidget {
    Q_OBJECT

public:
    GMainWindow(QWidget* parent = 0);
    ~GMainWindow();

private:
    void createObjects();
    void createConnexions();

protected:
    void closeEvent(QCloseEvent *event);

public slots:
    void slotSingleShot();

private:
    Ui::GMainWindow* ui;
};

#endif

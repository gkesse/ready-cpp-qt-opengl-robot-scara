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

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::GMainWindow* ui;
};

#endif

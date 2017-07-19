#ifndef _GStackedWidget_
#define _GStackedWidget_

#include <QWidget>
#include <QFrame>

namespace Ui {
class GStackedWidget;
}

class GStackedWidget : public QFrame { 
    Q_OBJECT
    
public:
    GStackedWidget(QWidget *parent = 0);
    ~GStackedWidget();
    
private:
    void createObjects();
    void createConnexions();

signals:
    void emitMenuClicked(const int&);

private:
    Ui::GStackedWidget* ui;
};

#endif

#ifndef _GGradientLinear_
#define _GGradientLinear_

#include <QWidget>
#include <QFrame>

class GGradientLinear : public QFrame {
    Q_OBJECT

public:
    GGradientLinear(QWidget* parent = 0);
    ~GGradientLinear();
    
private:
    void createObjects();
    void createConnexions();

protected:
    void paintEvent(QPaintEvent* event);
    QSize sizeHint() const;
};

#endif

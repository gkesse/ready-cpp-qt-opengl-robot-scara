#ifndef _GGraphicsView_
#define _GGraphicsView_

#include <QGraphicsView>

class GGraphicsView : public QGraphicsView {
    Q_OBJECT

public:
    GGraphicsView(QWidget* parent = 0);
    ~GGraphicsView();

private:
    void createObjects();
    void createConnexions();

protected:
    void resizeEvent(QResizeEvent* event);
};

#endif

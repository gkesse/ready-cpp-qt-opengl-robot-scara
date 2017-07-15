#ifndef _GCreateDatabase_
#define _GCreateDatabase_

#include <QWidget>
#include <QFrame>

namespace Ui {
class GCreateDatabase;
}

class GCreateDatabase : public QFrame {
    Q_OBJECT

public:
    GCreateDatabase(QWidget* parent = 0);
    ~GCreateDatabase();

private:
    void createObjects();
    void createConnexions();

private:
    Ui::GCreateDatabase* ui;
};

#endif

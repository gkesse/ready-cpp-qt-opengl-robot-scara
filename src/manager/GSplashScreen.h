#ifndef _GSplashScreen_
#define _GSplashScreen_

#include <QObject>
#include <QSplashScreen>
#include <QColor>

class GSplashScreen : public QObject {
    Q_OBJECT
    
private:
    GSplashScreen();

public:
    ~GSplashScreen();

public:
    static GSplashScreen* Instance();

public:
    void setPixmap(const QString& file);
    void show();
    void showMessage(const QString& msg, const QColor& color = QColor("#f67b20"));
    void finish(QWidget* mainWin);
    
private:
    static GSplashScreen* m_instance;
    QSplashScreen* m_splash;
    Qt::Alignment m_align;
};

#endif

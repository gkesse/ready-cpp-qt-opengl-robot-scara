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
    void setDelay(const int& delay = 5000);
    void show();
    void showMessage(const QString& msg, const QColor& color = QColor("orange"));
    void finish(QWidget* mainWindow);
    
private:
    static GSplashScreen* m_instance;
    QSplashScreen* m_splash;
    Qt::Alignment m_align;
};

#endif

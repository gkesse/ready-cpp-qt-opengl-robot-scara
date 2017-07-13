#include "GSplashScreen.h"
#include <QPixmap>
#include <QThread>

GSplashScreen* GSplashScreen::m_instance = 0;

GSplashScreen::GSplashScreen() {
    m_splash = new QSplashScreen;    
    m_align = Qt::AlignLeft | Qt::AlignVCenter;
}

GSplashScreen::~GSplashScreen() {
    
}

GSplashScreen* GSplashScreen::Instance() {
    if(m_instance == 0) {
        m_instance = new GSplashScreen;
    }
    
    return m_instance;
}

void GSplashScreen::setPixmap(const QString& file) {
    m_splash->setPixmap(QPixmap(file));
}

void GSplashScreen::setDelay(const int& delay) {
    QThread::msleep(delay);
}

void GSplashScreen::show() {
    m_splash->show();
}

void GSplashScreen::showMessage(const QString& msg, const QColor& color) {
    m_splash->showMessage(msg, m_align, color);
    QThread::msleep(200);
}

void GSplashScreen::finish(QWidget* mainWindow) {
    m_splash->finish(mainWindow);
}

#include "GSplashScreen.h"
#include <QPixmap>
#include <QThread>

GSplashScreen* GSplashScreen::m_instance = 0;

GSplashScreen::GSplashScreen() {
    createObjects();
    createConnexions();
}

GSplashScreen::~GSplashScreen() {
    
}

GSplashScreen* GSplashScreen::Instance() {
    if(m_instance == 0) {
        m_instance = new GSplashScreen;
    }
    
    return m_instance;
}

void GSplashScreen::createObjects() {
    m_splashScreen = new QSplashScreen;
    m_align = Qt::AlignLeft | Qt::AlignVCenter;

}

void GSplashScreen::createConnexions() {

}

void GSplashScreen::setPixmap(const QString& file) {
    m_splashScreen->setPixmap(QPixmap(file));
}

void GSplashScreen::setDelay(const int& delay) {
    QThread::msleep(delay);
}

void GSplashScreen::show() {
    m_splashScreen->show();
}

void GSplashScreen::showMessage(const QString& msg, const QColor& color) {
    m_splashScreen->showMessage(msg, m_align, color);
    QThread::msleep(200);
}

void GSplashScreen::finish(QWidget* mainWindow) {
    m_splashScreen->finish(mainWindow);
}


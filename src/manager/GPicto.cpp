#include "GPicto.h"
#include "GSplashScreen.h"
#include <QApplication>

GPicto* GPicto::m_instance = 0;

GPicto::GPicto() {
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GPicto : loading Picto module...");
}

GPicto::~GPicto() {
    
}

GPicto* GPicto::Instance() {
    if(m_instance == 0) {
        m_instance = new GPicto;
    }
    
    return m_instance;
}

void GPicto::createObjects() {
    m_picto = new QtAwesome(qApp);
    m_picto->initFontAwesome();
}

void GPicto::createConnexions() {
    
}

QIcon GPicto::getPicto(const int& picto, const QColor& color) const {
    m_picto->setDefaultOption("color", color);
    m_picto->setDefaultOption("color-active", color);
    return m_picto->icon(picto);
}

QIcon GPicto::getPicto(const QString& picto, const QColor& color) const {
    m_picto->setDefaultOption("color", color);
    m_picto->setDefaultOption("color-active", color);
    return m_picto->icon(picto);
}

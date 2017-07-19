#include "GDatabaseAccess.h"
#include "GSplashScreen.h"
#include "GMessageView.h"
#include <QSqlDatabase>

GDatabaseAccess* GDatabaseAccess::m_instance = 0;

GDatabaseAccess::GDatabaseAccess() {
    createObjects();
    createConnexions();
}

GDatabaseAccess::~GDatabaseAccess() {
    
}

GDatabaseAccess* GDatabaseAccess::Instance() {
    if(m_instance == 0) {
        m_instance = new GDatabaseAccess;
    }
    
    return m_instance;
}

void GDatabaseAccess::createObjects() {

}

void GDatabaseAccess::createConnexions() {
    
}

QStringList GDatabaseAccess::getDrivers() const {
    QStringList m_drivers = QSqlDatabase::drivers();
    return m_drivers;
}

void GDatabaseAccess::run() {
    QStringList m_drivers = QSqlDatabase::drivers();
    GMessageView::Instance()->showData(m_drivers, "m_drivers");
}

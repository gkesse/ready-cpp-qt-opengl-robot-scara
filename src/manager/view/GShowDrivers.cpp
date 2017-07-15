#include "GShowDrivers.h"
#include "ui_GShowDrivers.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include "GDatabaseAccess.h"
#include <QStringListModel>

GShowDrivers::GShowDrivers(QWidget* parent) :
    QFrame(parent), ui(new Ui::GShowDrivers) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GShowDrivers : loading GShowDrivers module...");
}

GShowDrivers::~GShowDrivers() {
    delete ui;
}

void GShowDrivers::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::cogs));

    QStringList m_drivers = GDatabaseAccess::Instance()->getDrivers();
    QStringListModel* m_model = new QStringListModel(this);
    m_model->setStringList(m_drivers);
    ui->m_listView->setModel(m_model);
}

void GShowDrivers::createConnexions() {
}

void GShowDrivers::slotCreateClicked() {
    GDatabaseAccess::Instance()->run();
}

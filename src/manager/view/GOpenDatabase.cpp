#include "GOpenDatabase.h"
#include "ui_GOpenDatabase.h"
#include "GSplashScreen.h"
#include "GPicto.h"

GOpenDatabase::GOpenDatabase(QWidget* parent) :
    QFrame(parent), ui(new Ui::GOpenDatabase) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GOpenDatabase : loading GOpenDatabase module...");
}

GOpenDatabase::~GOpenDatabase() {
    delete ui;
}

void GOpenDatabase::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::folderopen));
    ui->m_open->setIcon(GPicto::Instance()->getPicto(fa::folderopeno));

}

void GOpenDatabase::createConnexions() {

}

#include "GCreateDatabase.h"
#include "ui_GCreateDatabase.h"
#include "GSplashScreen.h"
#include "GPicto.h"

GCreateDatabase::GCreateDatabase(QWidget* parent) :
    QFrame(parent), ui(new Ui::GCreateDatabase) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GCreateDatabase : loading CreateDatabase module...");
}

GCreateDatabase::~GCreateDatabase() {
    delete ui;
}

void GCreateDatabase::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::cog));
}

void GCreateDatabase::createConnexions() {

}

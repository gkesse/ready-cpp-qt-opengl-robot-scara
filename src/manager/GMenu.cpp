#include "GMenu.h"
#include "ui_GMenu.h"
#include "GSplashScreen.h"
#include "GPicto.h"

GMenu::GMenu(QWidget* parent) :
    QFrame(parent), ui(new Ui::GMenu) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GMenu : loading Menu module...");
}

GMenu::~GMenu() {
    delete ui;
}

void GMenu::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::book));
    ui->m_openDatabase->setIcon(GPicto::Instance()->getPicto(fa::folderopen));
}

void GMenu::createConnexions() {

}

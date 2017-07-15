#include "GMenu.h"
#include "ui_GMenu.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include "GJson.h"
#include "GMessageView.h"

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

    GJson::Instance()->load("../../src/res/json/menu.json");
    QStringList m_menuName = GJson::Instance()->getArray("menu", "name");

    for(int i = 0; i < m_menuName.size(); i++) {
        QPushButton *m_button = new QPushButton;
        m_button->setText(m_menuName.at(i));
        m_button->setIcon(GPicto::Instance()->getPicto("book"));
        ui->m_menuLayout->addWidget(m_button);
    }
}

void GMenu::createConnexions() {

}

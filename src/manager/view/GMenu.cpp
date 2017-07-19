#include "GMenu.h"
#include "ui_GMenu.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include "GMessageView.h"

GMenu::GMenu(QWidget* parent) :
    QFrame(parent), ui(new Ui::GMenu) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GMenu : loading GMenu module...");
}

GMenu::~GMenu() {
    delete ui;
}

void GMenu::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::book));

    ui->m_graphicView->setIcon(GPicto::Instance()->getPicto(fa::chevronright));
    ui->m_createDatabase->setIcon(GPicto::Instance()->getPicto(fa::cog));
    ui->m_openDatabase->setIcon(GPicto::Instance()->getPicto(fa::folderopen));

    int m_count = 0;
    m_signalMapper = new QSignalMapper(this);
    m_signalMapper->setMapping(ui->m_graphicView, m_count++);
    m_signalMapper->setMapping(ui->m_createDatabase, m_count++);
    m_signalMapper->setMapping(ui->m_openDatabase, m_count++);

    m_buttonGroup = new QButtonGroup(this);
    m_buttonGroup->addButton(ui->m_graphicView);
    m_buttonGroup->addButton(ui->m_createDatabase);
    m_buttonGroup->addButton(ui->m_openDatabase);
}

void GMenu::createConnexions() {
    connect(ui->m_graphicView, SIGNAL(clicked()), m_signalMapper, SLOT(map()));
    connect(ui->m_createDatabase, SIGNAL(clicked()), m_signalMapper, SLOT(map()));
    connect(ui->m_openDatabase, SIGNAL(clicked()), m_signalMapper, SLOT(map()));
    connect(m_signalMapper, SIGNAL(mapped(int)), this, SIGNAL(emitMenuClicked(int)));
}

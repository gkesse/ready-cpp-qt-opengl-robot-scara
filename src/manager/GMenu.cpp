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
    GSplashScreen::Instance()->showMessage("GMenu : loading Menu module...");
}

GMenu::~GMenu() {
    delete ui;
}

void GMenu::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::book));

    ui->m_create->setIcon(GPicto::Instance()->getPicto(fa::cog));
    ui->m_open->setIcon(GPicto::Instance()->getPicto(fa::folderopen));

    int m_count = 0;
    m_signalMapper = new QSignalMapper(this);
    m_signalMapper->setMapping(ui->m_create, m_count++);
    m_signalMapper->setMapping(ui->m_open, m_count++);

    m_buttonGroup = new QButtonGroup(this);
    m_buttonGroup->addButton(ui->m_create);
    m_buttonGroup->addButton(ui->m_open);
}

void GMenu::createConnexions() {
    connect(ui->m_create, SIGNAL(clicked()), m_signalMapper, SLOT(map()));
    connect(ui->m_open, SIGNAL(clicked()), m_signalMapper, SLOT(map()));
    connect(m_signalMapper, SIGNAL(mapped(int)), this, SIGNAL(emitMenuClicked(int)));
}

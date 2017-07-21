#include "GMenu.h"
#include "ui_GMenu.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include "GJson.h"
#include "GTypeDef.h"
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
    GJson::Instance()->load(":/json/Menu.json");

    GArrayMap m_dataArray = GJson::Instance()->getArray("menu");
    m_signalMapper = new QSignalMapper;

    for(int i = 0; i < m_dataArray.size(); i++) {
        QPushButton* m_menu = new QPushButton;
        QVariantMap m_dataMap = m_dataArray.at(i);
        QString m_name = m_dataMap.value("name").toString();
        m_menu->setText(m_name);
        m_menu->setIcon(GPicto::Instance()->getPicto(fa::chevronright));
        m_menu->setAutoExclusive(true);
        m_menu->setCheckable(true);
        if(i == 0) m_menu->setChecked(true);
        m_menu->setCursor(Qt::PointingHandCursor);
        ui->m_menuLayout->addWidget(m_menu);
        m_signalMapper->setMapping(m_menu, i);
        m_menuMap.insert(m_name, m_menu);
    }

    ui->m_menuLayout->setAlignment(Qt::AlignTop);
}

void GMenu::createConnexions() {
    for(int i = 0; i < m_menuMap.size(); i++) {
        QPushButton* m_menu = m_menuMap.values().at(i);
        connect(m_menu, SIGNAL(clicked()), m_signalMapper, SLOT(map()));
    }
    connect(m_signalMapper, SIGNAL(mapped(int)), this, SIGNAL(emitMenuClicked(int)));
}

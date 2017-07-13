#include "GMessageView.h"
#include "ui_GMessageView.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include <QApplication>
#include <QDesktopWidget>

GMessageView* GMessageView::m_instance = 0;

GMessageView::GMessageView() :
    ui(new Ui::GMessageView) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    setPosition();
    show();
    GSplashScreen::Instance()->showMessage("GMessageView : loading MessageView module...");
}

GMessageView::~GMessageView() {
    delete ui;
}

GMessageView* GMessageView::Instance() {
    if(m_instance == 0) {
        m_instance =  new GMessageView;
    }

    return m_instance;
}

void GMessageView::createObjects() {

}

void GMessageView::createConnexions() {

}

void GMessageView::setPosition() {
    int m_viewW = 400;
    int m_viewH = 300;

    QSize m_desktopS = QApplication::desktop()->screenGeometry().size();
    int m_desktopW = m_desktopS.width();
    int m_desktopH = m_desktopS.height();

    int m_viewX = m_desktopW - m_viewW - 10;
    int m_viewY = m_desktopH - m_viewH - 50;

    setGeometry(m_viewX, m_viewY, m_viewW, m_viewH);
}

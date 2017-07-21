#include "GModelView.h"
#include "ui_GModelView.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include "GTableModel.h"

GModelView::GModelView(QWidget* parent) :
    QFrame(parent), ui(new Ui::GModelView) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GModelView : loading GModelView module...");
}

GModelView::~GModelView() {
    delete ui;
}

void GModelView::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::book));

    GTableModel* m_tableModel = new GTableModel;
    ui->m_tableView->setModel(m_tableModel);
}

void GModelView::createConnexions() {

}

#include "GGraphicsViewV.h"
#include "ui_GGraphicsViewV.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include "GGraphicsScene.h"

GGraphicsViewV::GGraphicsViewV(QWidget* parent) :
    QFrame(parent), ui(new Ui::GGraphicsViewV) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GGraphicsViewV : loading GGraphicsViewV module...");
}

GGraphicsViewV::~GGraphicsViewV() {
    delete ui;
}

void GGraphicsViewV::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::book));

    GGraphicsScene* m_scene = new GGraphicsScene(this);
    ui->m_graphicsView->setScene(m_scene);
}

void GGraphicsViewV::createConnexions() {

}


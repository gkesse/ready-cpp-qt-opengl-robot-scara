#include "GGradientView.h"
#include "ui_GGradientView.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include <QPainter>

GGradientView::GGradientView(QWidget* parent) :
    QFrame(parent), ui(new Ui::GGradientView) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GGradientView : loading GGradientView module...");
}

GGradientView::~GGradientView() {
    delete ui;
}

void GGradientView::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::book));
}

void GGradientView::createConnexions() {

}

#include "GStackedWidget.h"
#include "ui_GStackedWidget.h"
#include "GSplashScreen.h"

GStackedWidget::GStackedWidget(QWidget *parent) :
    QFrame(parent), ui(new Ui::GStackedWidget) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GStackedWidget : loading GStackedWidget module...");
}

GStackedWidget::~GStackedWidget() {
    delete ui;
}

void GStackedWidget::createObjects() {

}

void GStackedWidget::createConnexions() {
    connect(this, SIGNAL(emitMenuClicked(int)), ui->m_stackedWidget, SLOT(setCurrentIndex(int)));
}

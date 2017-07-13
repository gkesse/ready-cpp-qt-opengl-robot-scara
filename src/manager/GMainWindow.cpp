#include "GMainWindow.h"
#include "ui_GMainWindow.h"
#include "GSplashScreen.h"
#include "GMessageView.h"

GMainWindow::GMainWindow(QWidget* parent) :
    QWidget(parent), ui(new Ui::GMainWindow) {
    ui->setupUi(this);
    GMessageView::Instance();
    GSplashScreen::Instance()->showMessage("GMainWindow : loading MainWindow module...");
}

GMainWindow::~GMainWindow() {
    delete ui;
}

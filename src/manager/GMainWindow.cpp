#include "GMainWindow.h"
#include "ui_GMainWindow.h"
#include "GSplashScreen.h"

GMainWindow::GMainWindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::GMainWindow) {
    GSplashScreen::Instance()->showMessage("GMainWindow : loading mainwindow module...");
    ui->setupUi(this);
}

GMainWindow::~GMainWindow() {
    delete ui;
}

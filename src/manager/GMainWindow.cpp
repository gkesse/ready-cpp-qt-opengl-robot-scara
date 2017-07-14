#include "GMainWindow.h"
#include "ui_GMainWindow.h"
#include "GSplashScreen.h"
#include "GMessageView.h"
#include <QApplication>

GMainWindow::GMainWindow(QWidget* parent) :
    QWidget(parent), ui(new Ui::GMainWindow) {
    ui->setupUi(this);
    GMessageView::Instance();
    GMessageView::Instance()->show("Visualize your messages here...");
    GSplashScreen::Instance()->showMessage("GMainWindow : loading MainWindow module...");
}

GMainWindow::~GMainWindow() {
    delete ui;
}

void GMainWindow::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event)
    qApp->closeAllWindows();
}

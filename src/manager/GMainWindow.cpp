#include "GMainWindow.h"
#include "ui_GMainWindow.h"
#include "GSplashScreen.h"
#include "GMessageView.h"
#include <QApplication>
#include <QTimer>

GMainWindow::GMainWindow(QWidget* parent) :
    QWidget(parent), ui(new Ui::GMainWindow) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GMainWindow : loading MainWindow module...");
}

GMainWindow::~GMainWindow() {
    delete ui;
}

void GMainWindow::createObjects() {
    QTimer::singleShot(1000, this, SLOT(slotSingleShot()));
}

void GMainWindow::createConnexions() {

}

void GMainWindow::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event)
    qApp->closeAllWindows();
}

void GMainWindow::slotSingleShot() {
    GMessageView::Instance()->show();
}

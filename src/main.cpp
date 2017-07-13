#include "GMainWindow.h"
#include "GStyle.h"
#include "GSplashScreen.h"
#include <QApplication>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    GStyle::Instance()->load();

    GSplashScreen::Instance()->setPixmap(":/img/splash.png");
    GSplashScreen::Instance()->show();
    GSplashScreen::Instance()->showMessage("GStyle : loading style module...");

    GMainWindow* m_mainWindow = new GMainWindow;
    m_mainWindow->show();

    GSplashScreen::Instance()->finish(m_mainWindow);
    return app.exec();
}

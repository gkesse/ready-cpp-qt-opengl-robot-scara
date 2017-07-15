#include "GMainWindow.h"
#include "GStyle.h"
#include "GSplashScreen.h"
#include <QApplication>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    GStyle::Instance()->load();

    GSplashScreen::Instance()->setPixmap(":/img/splash.png");
    GSplashScreen::Instance()->show();
    //GSplashScreen::Instance()->setDelay();
    GSplashScreen::Instance()->showMessage("GSplashScreen : loading GSplashScreen module...");
    GSplashScreen::Instance()->showMessage("GStyle : loading GStyle module...");
    GSplashScreen::Instance()->showMessage("GMessageView : loading GMessageView module...");

    GMainWindow* m_mainWindow = new GMainWindow;
    m_mainWindow->show();

    GSplashScreen::Instance()->finish(m_mainWindow);
    return app.exec();
}

#include "GMainWindow.h"
#include "GStyle.h"
#include <QApplication>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    GStyle::Instance()->load();

    GMainWindow* m_mainWindow = new GMainWindow;
    m_mainWindow->show();

    return app.exec();
}

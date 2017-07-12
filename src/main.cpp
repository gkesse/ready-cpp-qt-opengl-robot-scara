#include "GMainWindow.h"
#include <QApplication>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    GMainWindow* m_mainWindow = new GMainWindow;
    m_mainWindow->show();

    return app.exec();
}

#include <QApplication>
#include <QWidget>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QWidget* m_mainWindow = new QWidget;
    m_mainWindow->show();

    return app.exec();
}

//===============================================
#include "GMainWindow.h"
//===============================================
int main(int _argc, char** _argv) {
    QApplication lApp(_argc, _argv);
    GMainWindow lWindow;
    lWindow.show();
    return lApp.exec();
}
//===============================================

include("C:\Users\TiaGerard\Downloads\QtAwesome\QtAwesome-master\QtAwesome-master\QtAwesome\QtAwesome.pri")

INCLUDEPATH += \
    $$PWD

FORMS += \
    $$PWD/GMainWindow.ui \
    $$PWD/GMenu.ui \
    $$PWD/GMessageView.ui \
    $$PWD/GStackedWidget.ui \
    $$PWD/GOpenDatabase.ui \
    $$PWD/GCreateDatabase.ui

HEADERS += \
    $$PWD/GMainWindow.h \
    $$PWD/GStyle.h \
    $$PWD/GSplashScreen.h \
    $$PWD/GMenu.h \
    $$PWD/GPicto.h \
    $$PWD/GMessageView.h \
    $$PWD/GStackedWidget.h \
    $$PWD/GOpenDatabase.h \
    $$PWD/GCreateDatabase.h \
    $$PWD/GJson.h

SOURCES += \
    $$PWD/GMainWindow.cpp \
    $$PWD/GStyle.cpp \
    $$PWD/GSplashScreen.cpp \
    $$PWD/GMenu.cpp \
    $$PWD/GPicto.cpp \
    $$PWD/GMessageView.cpp \
    $$PWD/GStackedWidget.cpp \
    $$PWD/GOpenDatabase.cpp \
    $$PWD/GCreateDatabase.cpp \
    $$PWD/GJson.cpp

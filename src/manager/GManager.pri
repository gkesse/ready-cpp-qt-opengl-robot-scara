include("C:\Users\TiaGerard\Downloads\QtAwesome\QtAwesome-master\QtAwesome-master\QtAwesome\QtAwesome.pri")

INCLUDEPATH += \
    $$PWD

FORMS += \
    $$PWD/GMainWindow.ui \
    $$PWD/GMenu.ui \
    $$PWD/GMessageView.ui

HEADERS += \
    $$PWD/GMainWindow.h \
    $$PWD/GStyle.h \
    $$PWD/GSplashScreen.h \
    $$PWD/GMenu.h \
    $$PWD/GPicto.h \
    $$PWD/GMessageView.h

SOURCES += \
    $$PWD/GMainWindow.cpp \
    $$PWD/GStyle.cpp \
    $$PWD/GSplashScreen.cpp \
    $$PWD/GMenu.cpp \
    $$PWD/GPicto.cpp \
    $$PWD/GMessageView.cpp

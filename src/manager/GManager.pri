include("C:\Users\TiaGerard\Downloads\QtAwesome\QtAwesome-master\QtAwesome-master\QtAwesome\QtAwesome.pri")
include(view/GView.pri)

INCLUDEPATH += \
    $$PWD

HEADERS += \
    $$PWD/GPicto.h \
    $$PWD/GSplashScreen.h \
    $$PWD/GStyle.h \
    $$PWD/GDatabaseAccess.h \
    $$PWD/GGraphicsScene.h \
    $$PWD/GGraphicsPixmapItem.h \
    $$PWD/GGraphicsWidget.h \
    $$PWD/GGraphicsView.h

SOURCES += \
    $$PWD/GPicto.cpp \
    $$PWD/GSplashScreen.cpp \
    $$PWD/GStyle.cpp \
    $$PWD/GDatabaseAccess.cpp \
    $$PWD/GGraphicsScene.cpp \
    $$PWD/GGraphicsPixmapItem.cpp \
    $$PWD/GGraphicsWidget.cpp \
    $$PWD/GGraphicsView.cpp


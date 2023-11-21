TEMPLATE = app
CONFIG += console c++17
QT += widgets openglwidgets

LIBS +=\
    -lopengl32 -lglu32  \

SOURCES += \
        GLWidget.cpp \
        GMainWindow.cpp \
        GModel.cpp \
        GScara.cpp \
        main.cpp

HEADERS += \
    GInclude.h \
    GLWidget.h \
    GMainWindow.h \
    GModel.h \
    GScara.h

FORMS += \
    GMainWindow.ui

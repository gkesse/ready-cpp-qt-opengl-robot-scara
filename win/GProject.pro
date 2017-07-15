TEMPLATE = app
TARGET = main
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
RCC_DIR = build
CONFIG += release
QT += widgets sql

include(../src/GMain.pri)

#-------------------------------------------------
#
# Project created by QtCreator 2014-11-02T21:53:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HelloQtOnAndroid
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

CONFIG += mobility
MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml

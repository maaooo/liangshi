# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = teach
DESTDIR = ../../Win32/Release
QT += core network script scripttools widgets gui
//CONFIG += debug staticlib
CONFIG += release staticlib
DEFINES += WIN64 QT_DLL QT_WIDGETS_LIB QT_NETWORK_LIB QT_SCRIPT_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Release
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/release
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(teach.pri)
win32:RC_FILE = teach.rc
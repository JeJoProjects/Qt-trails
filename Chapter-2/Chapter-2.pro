#-------------------------------------------------
#
# Project created by QtCreator 2019-01-15T19:58:44
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = Chapter-2
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp \
    MainWindow.cpp \
    SysInfo.cpp \
    CpuWidget.cpp \
    MemoryWidget.cpp \
    SysInfoWidget.cpp \


HEADERS += MainWindow.h \
    SysInfo.h \
    CpuWidget.h \
    MemoryWidget.h \
    SysInfoWidget.h \

windows {
    SOURCES += SysInfoWindowsImpl.cpp
    HEADERS += SysInfoWindowsImpl.h
}

linux {
    SOURCES += SysInfoLinuxImpl.cpp
    HEADERS += SysInfoLinuxImpl.h
}

FORMS   += MainWindow.ui


#-------------------------------------------------
#
# Project created by QtCreator 2019-01-15T19:58:44
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = Chapter-2
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += MainApplication.cpp \
           MainWindow.cpp \
           SysInfo.cpp \
           SysInfoWidget.cpp \


HEADERS += MainWindow.h \
           SysInfo.h \
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


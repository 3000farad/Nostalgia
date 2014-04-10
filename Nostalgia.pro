#-------------------------------------------------
#
# Project created by QtCreator 2014-04-07T20:16:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Nostalgia
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    media.cpp \
    mediacontainer.cpp \
    audioplayer.cpp

HEADERS  += mainwindow.h \
    media.h \
    mediacontainer.h \
    audioplayer.h

FORMS    += mainwindow.ui

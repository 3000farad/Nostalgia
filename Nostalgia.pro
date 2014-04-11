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
    audioplayer.cpp \
    song.cpp \
    mediacontainer.cpp \
    librarymanager.cpp

HEADERS  += mainwindow.h \
    media.h \
    audioplayer.h \
    song.h \
    mediacontainer.h \
    librarymanager.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    DevNotes.txt

RESOURCES += \
    Resources.qrc

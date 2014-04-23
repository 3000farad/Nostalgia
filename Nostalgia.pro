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
    librarymanager.cpp \
    librarycontainer.cpp

HEADERS  += mainwindow.h \
    media.h \
    audioplayer.h \
    song.h \
    librarymanager.h \
    librarycontainer.h

#FORMS    += mainwindow.ui

TRANSLATIONS += nostalgia_es.ts

OTHER_FILES += \
    DevNotes.txt

RESOURCES += \
    Resources.qrc

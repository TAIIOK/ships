#-------------------------------------------------
#
# Project created by QtCreator 2015-08-01T13:11:45
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ships
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    board.cpp \
    computer.cpp \
    checkcoords.cpp

HEADERS += \
    game.h \
    board.h \
    computer.h \
    checkcoords.h

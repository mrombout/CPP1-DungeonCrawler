#-------------------------------------------------
#
# Project created by QtCreator 2015-09-26T13:37:18
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = DungeonCrawler
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += Launcher\main.cpp \
    Engine\command.cpp \
    Engine\game.cpp \
    Game/Action/sayaction.cpp \
    Game/State/welcomestate.cpp

HEADERS += \
    Engine\command.h \
    Engine\game.h \
    Engine/statemanager.h \
    Engine/state.h \
    Game/Action/sayaction.h \
    Game/Action/action.h \
    Game/State/welcomestate.h

DISTFILES += \
    Assets/intro.txt

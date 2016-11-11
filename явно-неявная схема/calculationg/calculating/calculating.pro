QT += core
QT -= gui

CONFIG += c++11

TARGET = calculating
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    calculating.cpp

HEADERS += \
    calculating.h

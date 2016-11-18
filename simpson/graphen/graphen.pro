#-------------------------------------------------
#
# Project created by QtCreator 2016-11-18T21:07:52
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graphen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../simpson-x2/simpson-x2/cGauss.cpp \
    ../simpson-x2/simpson-x2/cMatrix.cpp \
    ../simpson-x2/simpson-x2/cSimpson.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    ../simpson-x2/simpson-x2/cAbstractFunction.h \
    ../simpson-x2/simpson-x2/cGauss.h \
    ../simpson-x2/simpson-x2/cMatrix.h \
    ../simpson-x2/simpson-x2/cSimpson.h \
    qcustomplot.h

FORMS    += mainwindow.ui

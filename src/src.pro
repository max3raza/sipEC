CONFIG += qt debug
DEPENDPATH = ../include
TARGET = sipEC
QT += network
TEMPLATE = app
SOURCES += proxy.cpp \
    cwindow.cpp \
    mainwindow.cpp \
    main.cpp
INCLUDEPATH += .. \
            . \
            ../include
OBJECTS_DIR = ../obj
HEADERS += proxy.h
HEADERS += cwindow.h
HEADERS += mainwindow.h
DESTDIR = ../bin


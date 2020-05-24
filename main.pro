TEMPLATE = app
TARGET = draw_test 

QT += core gui widgets serialport concurrent

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += sdk_no_version_check
CONFIG += c++17
CONFIG += debug

CONFIG(release, debug|release) {
    CONFIG += optimize_full
}

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/widgets/mainwindow.cpp \
    $$PWD/widgets/renderarea.cpp \
    $$PWD/library/shapebase.cpp \
    $$PWD/library/lineshape.cpp \
    $$PWD/library/pointsshape.cpp \
    $$PWD/library/polylineshape.cpp \
    $$PWD/library/rectshape.cpp \
    $$PWD/library/ellipseshape.cpp

HEADERS += \
    $$PWD/widgets/mainwindow.hpp \
    $$PWD/widgets/renderarea.hpp
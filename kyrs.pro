QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    _2fastmath.cpp \
    _3fastmath.cpp \
    _4fastmath.cpp \
    avtoriz.cpp \
    fastmath.cpp \
    glavnoe.cpp \
    interestingmath.cpp \
    main.cpp \
    profile.cpp \
    start.cpp \
    tablymnozh.cpp \
    trueorfalse.cpp \
    xod.cpp

HEADERS += \
    _2fastmath.h \
    _3fastmath.h \
    _4fastmath.h \
    avtoriz.h \
    fastmath.h \
    glavnoe.h \
    interestingmath.h \
    profile.h \
    start.h \
    tablymnozh.h \
    trueorfalse.h \
    xod.h

FORMS += \
    _2fastmath.ui \
    _3fastmath.ui \
    _4fastmath.ui \
    avtoriz.ui \
    fastmath.ui \
    glavnoe.ui \
    interestingmath.ui \
    profile.ui \
    start.ui \
    tablymnozh.ui \
    trueorfalse.ui \
    xod.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

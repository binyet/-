#-------------------------------------------------
#
# Project created by QtCreator 2016-07-18T17:22:07
#
#-------------------------------------------------

QT       += core gui

TARGET = wlw
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    posix_qextserialport.cpp \
    qextserialbase.cpp \
    serialcom.cpp \
    enddevice.cpp \
    motor.cpp \
    t_h_l.cpp \
    ultra.cpp \
    ray.cpp \
    pwm.cpp

HEADERS  += mainwindow.h \
    posix_qextserialport.h \
    qextserialbase.h \
    serialcom.h \
    enddevice.h \
    motor.h \
    t_h_l.h \
    ultra.h \
    ray.h \
    pwm.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    wlw.pro.user

RESOURCES += \
    res.qrc

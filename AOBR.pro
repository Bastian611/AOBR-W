QT       += core gui opengl
QT       += network websockets
QT       += multimedia multimediawidgets quickwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += __STDC_FORMAT_MACROS

INCLUDEPATH += $$PWD/3rd/QtOpenGLPlayer/inc

LIBS += -L$$PWD/3rd/QtOpenGLPlayer/lib/ -lavcodec \
        -lavdevice \
        -lavfilter \
        -lavformat \
        -lavutil \
        -lswscale \
        -lswresample \


SOURCES += \
    src/DaulLightCamera/QOwWarnning.cpp \
    src/DaulLightCamera/QDaulLightCamera.cpp \
    src/DaulLightCamera/ffmpeg.cpp \
    src/DaulLightCamera/myglwidget.cpp \
    src/DaulLightCamera/rtsp.cpp \
    src/DaulLightCamera/widget.cpp \
    src/acousticcontrol/acousticcontrol.cpp \
    src/acousticcontrol/acousticcontroloption.cpp \
    src/acousticcontrol/acousticcontroludp.cpp \
    src/gimbal/gimbal.cpp \
    src/gimbal/gimbaloption.cpp \
    src/json/jsondata.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/stronglight/stronglight.cpp \
    src/stronglight/stronglightoption.cpp

HEADERS += \
    inc/QOwWarnning.h \
    inc/QDaulLightCamera.h \
    inc/acousticcontrol.h \
    inc/acousticcontroloption.h \
    inc/acousticcontroludp.h \
    inc/ffmpeg.h \
    inc/gimbal.h \
    inc/gimbaloption.h \
    inc/jsondata.h \
    inc/mainwindow.h \
    inc/myglwidget.h \
    inc/rtsp.h \
    inc/stronglight.h \
    inc/stronglightoption.h \
    inc/widget.h

FORMS += \
    ui/QOwWarnning.ui \
    ui/QDaulLightCamera.ui \
    ui/acousticcontroloption.ui \
    ui/gimbaloption.ui \
    ui/mainwindow.ui \
    ui/stronglightoption.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    photos.qrc

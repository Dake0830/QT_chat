QT       += core gui network  multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../common/handler.cpp \
    ../common/streamer.cpp \
    chatroomwidget.cpp \
    client.cpp \
    clienthandler.cpp \
    giftwidget.cpp \
    loginwidget.cpp \
    main.cpp \
    roomcreatwidget.cpp \
    roomwidget.cpp

HEADERS += \
    ../common/handler.h \
    ../common/singleton.h \
    ../common/streamer.h \
    chatroomwidget.h \
    client.h \
    clienthandler.h \
    giftwidget.h \
    loginwidget.h \
    roomcreatwidget.h \
    roomwidget.h

FORMS += \
    chatroomwidget.ui \
    giftwidget.ui \
    loginwidget.ui \
    roomcreatwidget.ui \
    roomwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

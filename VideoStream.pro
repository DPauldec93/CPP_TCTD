QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    videostream.cpp

HEADERS += \
    videostream.h

FORMS += \
    videostream.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -LD:\opencv_build\install\x64\vc15\lib -lopencv_core470 -lopencv_imgproc470 -lopencv_highgui470 -lopencv_imgcodecs470 -lopencv_videoio470 -lopencv_video470 -lopencv_calib3d470 -lopencv_photo470 -lopencv_features2d470
INCLUDEPATH += D:\opencv_build\install\include
DEPENDPATH += D:\opencv_build\install\include


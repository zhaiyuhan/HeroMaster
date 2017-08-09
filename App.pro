#-------------------------------------------------
#
# Project created by QtCreator 2017-07-13T10:32:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = App
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    View/AboutView/AboutView.cpp \
    Foundation/CustomShadowEffect.cpp \
    CustomView/MainView.cpp \
    CustomView/FileBrowser.cpp \
    View/HelpView.cpp \
    CustomView/Plane/OutPutPlane.cpp \
    CustomView/Plane/InformationPlane.cpp \
    CustomView/ControlPlaneView.cpp \
    CustomView/Plane/PlaneForTextView.cpp \
    CustomView/Plane/PlaneForAudioPlane.cpp \
    CustomView/Plane/PlaneForVideoView.cpp \
    CustomView/Plane/PlaneForCameraView.cpp \
    Foundation/SearchLineEdit.cpp \
    CustomView/AudioView.cpp

HEADERS += \
        mainwindow.h \
    View/AboutView/AboutView.h \
    Foundation/CustomShadowEffect.h \
    CustomView/MainView.h \
    CustomView/FileBrowser.h \
    View/HelpView.h \
    CustomView/Plane/OutPutPlane.h \
    CustomView/Plane/InformationPlane.h \
    CustomView/ControlPlaneView.h \
    CustomView/Plane/PlaneForTextView.h \
    CustomView/Plane/PlaneForAudioPlane.h \
    CustomView/Plane/PlaneForVideoView.h \
    CustomView/Plane/PlaneForCameraView.h \
    Foundation/SearchLineEdit.h \
    CustomView/AudioView.h


RESOURCES += \
    Resources/toolbaricons.qrc \
    Resources/basic.qrc \
    Resources/dockwidget.qrc \
    Resources/combobox.qrc \

FORMS += \
    View/AboutView/AboutView.ui \
    View/HelpView.ui

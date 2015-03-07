QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "Virtual Screen Splitter"

HEADERS += \
    windowcontroller.h \
    tray.h \
    settingswidget.h \
    WindowInfo.h \
    widgetwindow.h

SOURCES += \
    windowcontroller.cpp \
    main.cpp \
    tray.cpp \
    settingswidget.cpp \
    widgetwindow.cpp




RESOURCES += \
    res.qrc

RC_FILE = myapp.rc

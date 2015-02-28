QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    windowcontroller.h \
    tray.h \
    settingswidget.h

SOURCES += \
    windowcontroller.cpp \
    main.cpp \
    tray.cpp \
    settingswidget.cpp

RESOURCES += \
    res.qrc

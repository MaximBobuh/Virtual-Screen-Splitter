#ifndef TRAY_H
#define TRAY_H
#include <QMenu>
#include <QSystemTrayIcon>
#include "windowcontroller.h"
#include "settingswidget.h"

//Widget for control features the virtual desktop

class Tray : public QObject
{
    Q_OBJECT
public:
    Tray();

protected:
    void createMenu();
    void createSettings();

protected slots:
    void slotSettings();
    void slotShowHide();

private:
    QMenu* menu;
    QSystemTrayIcon* trayIcon;
    WindowController controller;
    SettingsWidget settings;
};

#endif // TRAY_H

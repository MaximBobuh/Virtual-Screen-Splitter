#ifndef TRAY_H
#define TRAY_H
#include <QLabel>
#include <QMenu>
#include <QSystemTrayIcon>
#include "windowcontroller.h"

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
    void slotAbout(){}
    void slotShowHide();

private:
    QMenu* menu;
    QSystemTrayIcon* trayIcon;
    WindowController* controller;
};

#endif // TRAY_H

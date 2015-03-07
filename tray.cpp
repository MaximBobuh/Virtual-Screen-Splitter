#include "tray.h"
#include <QApplication>

Tray::Tray()
{    
    connect(&settings, SIGNAL(signalApply(WindowsLayout, const WindowInfo*)), &controller,
            SLOT(slotApply(WindowsLayout, const WindowInfo*)));
    createMenu();
}

//===========================================================


void Tray::createMenu()
{
    QAction* Show = new QAction("Show/Hide", this);
    connect(Show, SIGNAL(triggered()), SLOT(slotShowHide()));

    QAction* Setting = new QAction("Setting", this);
    connect(Setting, SIGNAL(triggered()), SLOT(slotSettings()));

    QAction* Quit   = new QAction("Quit", this);
    connect(Quit, SIGNAL(triggered()), qApp, SLOT(quit()));

    menu = new QMenu;
    menu->addAction(Show);
    menu->addAction(Setting);
    menu->addAction(Quit);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(menu);
    trayIcon->setToolTip("Virtual Screen Splitter");
    trayIcon->setIcon(QPixmap("://images.jpg"));

    trayIcon->show();
}

//=====================================================


void Tray::slotShowHide()
{
    controller.showHide();
}

//=====================================================


void Tray::slotSettings()
{
    settings.loadWindowList();
    settings.setVisible(true);
}



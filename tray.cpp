#include "tray.h"
#include <QApplication>

Tray::Tray()
{
    controller = new WindowController;
    controller->show();
    createMenu();
}

//===========================================================


void Tray::createMenu()
{
    QAction* Show = new QAction("Show/Hide", this);
    connect(Show, SIGNAL(triggered()), SLOT(slotShowHide()));

    QAction* Setting = new QAction("Setting", this);
    connect(Setting, SIGNAL(triggered()), SLOT(slotSettings()));

    QAction* About = new QAction("About", this);
    connect(About, SIGNAL(triggered()), SLOT(slotAbout()));

    QAction* Quit   = new QAction("Quit", this);
    connect(Quit, SIGNAL(triggered()), qApp, SLOT(quit()));

    menu = new QMenu;
    menu->addAction(Show);
    menu->addAction(Setting);
    menu->addAction(About);
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
    controller->setVisible(!controller->isVisible());
}

//=====================================================


void Tray::slotSettings()
{

}



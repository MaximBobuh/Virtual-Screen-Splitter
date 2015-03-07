#include <QApplication>
#include "tray.h"




int main(int argv, char** argc)
{
    QApplication app(argv, argc);

    Tray win;

    QApplication::setQuitOnLastWindowClosed(false);

    return app.exec();
}

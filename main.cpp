#include <QApplication>
#include "windowcontroller.h"

int main(int argv, char** argc)
{
    QApplication app(argv, argc);

    WindowController win;
    win.show();

    return app.exec();
}

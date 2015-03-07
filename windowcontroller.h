#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QMouseEvent>
#include <WindowInfo.h>
#include "WidgetWindow.h"



//Main class for control the placement of windows
class WindowController : public QWidget
{
    Q_OBJECT
public:
    WindowController(QWidget* parent = 0);

    void setType(WindowsLayout);
    void showHide();

    void paintEvent(QPaintEvent*);


public slots:
    void slotApply(WindowsLayout, const WindowInfo*);

private:
    QVector<WidgetWindow*> windows;
    WindowsLayout currentType;
    int size;
};

#endif // WINDOWCONTROLLER_H

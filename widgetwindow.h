#ifndef WIDGETWINDOW_H
#define WIDGETWINDOW_H
#include <QLabel>
#include "WindowInfo.h"

//Widget for control behavior the child window

class WidgetWindow : public QLabel
{
public:
    WidgetWindow(QWidget* parent = 0);

    void setHwnd(HWND);                //set child
    void setPos();                     //new position
    void setHide(bool);                //show/hide
    void updateStyle();


    const WindowInfo& getChild() const { return child;}

private:
    WindowInfo child;
    bool styleInv;
};

#endif // WIDGETWINDOW_H

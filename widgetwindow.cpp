#include "widgetwindow.h"
#include <QDebug>

WidgetWindow::WidgetWindow(QWidget *parent) : QLabel(parent)
{
    QPixmap pix(":/null.jpg");
    setPixmap(pix);
}

//======================================================================================


void WidgetWindow::updateStyle()
{
    long Style = GetWindowLong(child.hWnd,GWL_STYLE);
    Style = Style ^ WS_OVERLAPPEDWINDOW;
    SetWindowLong(child.hWnd,GWL_STYLE,Style);

    styleInv = !styleInv;
}


//======================================================================================


void WidgetWindow::setPos()
{
    setHide(false);

    QPoint pos = this->mapToGlobal( QPoint(0,0) );
    SetWindowPos(child.hWnd, NULL, pos.x(), pos.y(), width(), height(), SWP_SHOWWINDOW);

    SetForegroundWindow(child.hWnd);
}


//======================================================================================

void WidgetWindow::setHwnd(HWND hWnd)
{
    child.hWnd = hWnd;

    if(isVisible())
        setPos();
}

//======================================================================================

void WidgetWindow::setHide(bool flag)
{
    if(flag)
        ShowWindow(child.hWnd,SW_SHOWMINIMIZED);
    else
        ShowWindow(child.hWnd,SW_RESTORE);
}

//======================================================================================

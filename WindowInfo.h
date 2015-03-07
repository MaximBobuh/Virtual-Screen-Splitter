#ifndef WINDOWINFO_H
#define WINDOWINFO_H
#include <QString>
#include <windows.h>

enum WindowsLayout {VDOUBLE, HDOUBLE, VTRIPLE,  LTRIPLE, RTRIPLE, TTRIPLE, BTRIPLE, QUAD };


//stuct which contains whose information about window
struct WindowInfo
{
    WindowInfo() : name("-------"), hWnd(NULL) {}
    WindowInfo(const QString& str, HWND h) : name(str), hWnd(h) {}

    QString name;
    HWND hWnd;
};

inline bool operator ==(const WindowInfo& first, const WindowInfo& second)
{
    return first.hWnd == second.hWnd;
}



#endif // WINDOWINFO_H

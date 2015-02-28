#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include <QWidget>
#include <QBoxLayout>
#include <QMouseEvent>

enum WindowsLayout {VDOUBLE, HDOUBLE, VTRIPLE,  LTRIPLE, RTRIPLE, TTRIPLE, BTRIPLE, QUAD };



class WindowController : public QWidget
{
    Q_OBJECT
public:
    WindowController(QWidget* parent = 0);

    void mousePressEvent(QMouseEvent*) { currentType = static_cast<WindowsLayout>(currentType + 1); setType(currentType);}
    void setType(WindowsLayout);
    //void addWindow(QWidget*, int);

private:
    QVector<QWidget*> windows;
    WindowsLayout currentType;
};

#endif // WINDOWCONTROLLER_H

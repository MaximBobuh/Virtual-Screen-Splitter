#include "settingswidget.h"
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include <algorithm>


QVector<WindowInfo> SettingsWidget::allWindows;

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent), currentType(VDOUBLE)
{
    createBox();

    lbl.setFixedSize(400, 240);
    setFixedSize(400, 420);
    setWindowTitle("Settings");
}

//================================================================

void SettingsWidget::createBox()
{
    loadWindowList();
    slotNextImage(currentType);


    QStringList str;
    str << "Double(vertical)" << "Double(horizontal)" << "Triple(vertical)"
        << "Triple(major at left)" << "Triple(major at right)" << "Triple(major at top)"
        << "Triple(major at bottom)" << "Quad";

    box[0].addItems(str);
    connect(&box[0], SIGNAL(currentIndexChanged(int)), SLOT(slotNextImage(int)));


    QPushButton* apply = new QPushButton("Apply");
    QPushButton*close = new QPushButton("Close");
    connect(apply, SIGNAL(clicked()), SLOT(slotApply()));
    connect(close, SIGNAL(clicked()), SLOT(close()));

    QLabel* signWindow = new QLabel[4];
    for(int i = 0; i < 4; ++i)
    {
        signWindow[i].setText("window " + QString::number(i + 1) + ":");
        signWindow->setParent(this);
    }


    QGridLayout* layout = new QGridLayout;
    layout->addWidget(&box[0], 0, 0, 1, 2);
    layout->addWidget(&lbl, 1, 0, 1, 4);

    layout->addWidget(&signWindow[0], 2, 0 );
    layout->addWidget(&box[1], 2, 1, 1, 4 );
    layout->addWidget(&signWindow[1], 3, 0);
    layout->addWidget(&box[2], 3, 1, 1, 4);

    layout->addWidget(&signWindow[2], 4, 0);
    layout->addWidget(&box[3], 4, 1, 1, 4);
    layout->addWidget(&signWindow[3], 5, 0);
    layout->addWidget(&box[4], 5, 1, 1, 4);

    layout->addWidget(apply, 6, 2);
    layout->addWidget(close, 6, 3);

    setLayout(layout);
}


//====================================================================

void SettingsWidget::slotNextImage(int i)
{
    QPixmap pix(":/" + QString::number(i + 1) + ".png");
    lbl.setPixmap(pix);

    oldType = (WindowsLayout)i;
}

//====================================================================

void SettingsWidget::slotApply()
{
    for(int i = 0; i < 4; ++i)
        info[i] = allWindows[box[i+1].currentIndex()];

    currentType = oldType;

    setVisible(false);

    emit signalApply(currentType, info);
}

//=====================================================================

void SettingsWidget::closeEvent(QCloseEvent *)
{
    setVisible(false);
    slotNextImage(currentType);
}

//======================================================================

BOOL CALLBACK EnumChildProc(HWND hWnd,LPARAM lParam)
{
    TCHAR buff[260];
    QString str;
    if(!IsWindowVisible(hWnd)) return TRUE;


    GetWindowText(hWnd, buff, 260);
    str = QString::fromWCharArray(buff);

    if(!str.isEmpty() && str != "Program Manager" &&  str != "Virtual Screen Splitter")
        SettingsWidget::allWindows << WindowInfo(QString::fromWCharArray(buff), hWnd);        


    return TRUE;
}

//======================================================================

void SettingsWidget::loadWindowList()
{
    QString buf;
    QStringList list;

    allWindows.clear();
    allWindows << WindowInfo();

    EnumWindows(EnumChildProc, 0);

    for(int i = 0; i < allWindows.size(); ++i)
        list << allWindows[i].name;


    for(int i = 1; i < 5; ++i)
    {
        QVector<WindowInfo>::iterator pos = std::find(allWindows.begin(), allWindows.end(), info[i - 1]);
        if(pos == allWindows.end())
            pos = allWindows.begin();

        box[i].clear();
        box[i].addItems(list);

        info[i - 1] = *pos;
        box[i].setCurrentText(pos->name);
    }
}

//======================================================================



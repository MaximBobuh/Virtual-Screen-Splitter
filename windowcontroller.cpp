#include "windowcontroller.h"
#include <QPalette>
#include <QTextEdit>

WindowController::WindowController(QWidget *parent) : QWidget(parent), currentType(VDOUBLE)
{
    setWindowState(Qt::WindowMaximized);

    for(int i = 0; i < 4; ++i)
        windows.push_back(new QTextEdit(this));

    setType(currentType);
}


//==========================================================================================


void WindowController::setType(WindowsLayout type)
{
    QGridLayout* currentLayout = new QGridLayout;
    windows[2]->setHidden(true);
    windows[3]->setHidden(true);

    switch(type)
    {
    case QUAD:
        currentLayout->addWidget(windows[0], 0, 0);
        currentLayout->addWidget(windows[1], 0, 1);
        currentLayout->addWidget(windows[2], 1, 0);
        currentLayout->addWidget(windows[3], 1, 1);
        break;

    case VTRIPLE:
        currentLayout->addWidget(windows[0], 0, 0);
        currentLayout->addWidget(windows[1], 0, 1);
        currentLayout->addWidget(windows[2], 0, 2);
        break;

    case LTRIPLE:
        currentLayout->addWidget(windows[0], 0, 0, 2, 1);
        currentLayout->addWidget(windows[1], 0, 1);
        currentLayout->addWidget(windows[2], 1, 1);

        break;

    case RTRIPLE:
        currentLayout->addWidget(windows[0], 0, 0);
        currentLayout->addWidget(windows[1], 1, 0);
        currentLayout->addWidget(windows[2], 0, 1, 2, 1);
        break;

    case TTRIPLE:
        currentLayout->addWidget(windows[0], 0, 0, 1, 2);
        currentLayout->addWidget(windows[1], 1, 0);
        currentLayout->addWidget(windows[2], 1, 1);
        break;

    case BTRIPLE:
        currentLayout->addWidget(windows[0], 0, 0);
        currentLayout->addWidget(windows[1], 0, 1);
        currentLayout->addWidget(windows[2], 1, 0, 1, 2);
        break;

    case VDOUBLE:
        currentLayout->addWidget(windows[0], 0, 0);
        currentLayout->addWidget(windows[1], 0, 1);
        windows[2]->setHidden(true);
        break;

    case HDOUBLE:
        currentLayout->addWidget(windows[0], 0, 0);
        currentLayout->addWidget(windows[1], 1, 0);
        windows[2]->setHidden(true);
        break;
    }

    if(type == QUAD)
        windows[3]->setHidden(false);
    if(type > 1)
        windows[2]->setHidden(false);


    delete this->layout();
    setLayout(currentLayout);
}

//============================================================================

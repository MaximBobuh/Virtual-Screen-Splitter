#include "settingswidget.h"
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent)
{
    createBox();
    lbl.setFixedSize(400, 250);
    setFixedSize(400, 370);
}

//================================================================

void SettingsWidget::createBox()
{
    QStringList str;
    str << "Double(vertical)" << "Double(horizontal)" << "Triple(vertical)"
        << "Triple(major at left)" << "Triple(major at right)" << "Triple(major at top)"
        << "Triple(major at bottom)" << "Quad";

    box[0].addItems(str);
    connect(&box[0], SIGNAL(currentIndexChanged(int)), SLOT(slotNextImage(int)));

    windows << "------";
    for(int i = 1; i < 5; ++i)
        box[i].addItems(windows);

    slotNextImage(0);


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

    layout->addWidget(&signWindow[0], 3, 0);
    layout->addWidget(&box[1], 4, 0);
    layout->addWidget(&signWindow[1], 3, 1);
    layout->addWidget(&box[2], 4, 1);

    layout->addWidget(&signWindow[2], 3, 2);
    layout->addWidget(&box[3], 4, 2);
    layout->addWidget(&signWindow[3], 3, 3);
    layout->addWidget(&box[4], 4, 3);

    layout->addWidget(apply, 7, 2);
    layout->addWidget(close, 7, 3);

    setLayout(layout);
}


//====================================================================

void SettingsWidget::slotNextImage(int i)
{
    QPixmap pix(":/" + QString::number(i + 1) + ".png");
    lbl.setPixmap(pix);
}

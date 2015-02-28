#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H
#include <QWidget>
#include <QComboBox>
#include <QLabel>

class SettingsWidget : public QWidget
{
    Q_OBJECT
public:
    SettingsWidget(QWidget* parent = 0);

public slots:
    void slotApply(){;}
    void slotNextImage(int);

private:
    void createBox();
    QComboBox box[5];
    QStringList windows;
    QLabel lbl;
};

#endif // SETTINGSWIDGET_H

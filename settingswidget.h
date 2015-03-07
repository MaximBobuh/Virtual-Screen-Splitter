#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <WindowInfo.h>


class SettingsWidget : public QWidget
{
    Q_OBJECT
    friend BOOL CALLBACK EnumChildProc(HWND hWnd,LPARAM lParam);

public:
    SettingsWidget(QWidget* parent = 0);
    void loadWindowList();

public slots:
    void slotApply();
    void slotNextImage(int);

signals:
    void signalApply(WindowsLayout, const WindowInfo*);

private:
    void createBox();
    void closeEvent(QCloseEvent *);

    WindowsLayout currentType, oldType;
    QComboBox box[5];
    WindowInfo info[4];
    static QVector<WindowInfo> allWindows;
    QLabel lbl;
};

#endif // SETTINGSWIDGET_H

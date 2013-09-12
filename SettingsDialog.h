#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QFile>
#include <QTextStream>

class SettingsDialog : public QDialog
{
Q_OBJECT

public:
    SettingsDialog(QWidget* parent = 0);

    void SetFile(QFile* settingsFile);

private:
    QVBoxLayout* centralLayout;
    QHBoxLayout* timeLayout;
    QLabel* timeLabel;
    QSpinBox* pomodoroSpin;
    QSpinBox* breakSpin;

};

#endif // SETTINGSDIALOG_H

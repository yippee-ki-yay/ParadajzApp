#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QSettings>
#include <QComboBox>

class SettingsDialog : public QDialog
{
Q_OBJECT

public:
    SettingsDialog(QWidget* parent = 0);

private slots:
    void MakeChanges();

signals:
    void Changed();

private:
    QVBoxLayout* centralLayout;

    QHBoxLayout* pomodoroTimeLayout;
    QHBoxLayout* breakTimeLayout;
    QHBoxLayout* longBreakLayout;
    QHBoxLayout* historyLayout;

    QLabel* timeLabel;
    QLabel* breakLabel;
    QSpinBox* pomodoroSpin;
    QSpinBox* breakSpin;
    QPushButton* submitButton;

    QLabel* longBreakLabel;
    QSpinBox* longBreakSpin;

    QLabel* historyLabel;
    QComboBox* historyCombo;

};

#endif // SETTINGSDIALOG_H

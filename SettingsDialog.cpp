#include "SettingsDialog.h"

SettingsDialog::SettingsDialog(QWidget* parent): QDialog(parent)
{
    centralLayout = new QVBoxLayout(this);

    pomodoroTimeLayout = new QHBoxLayout;

    breakTimeLayout = new QHBoxLayout;

    longBreakLayout = new QHBoxLayout;

    historyLayout = new QHBoxLayout;

    timeLabel = new QLabel("Change Pomodoro time", this);

    breakLabel = new QLabel("Change break time", this);

    pomodoroSpin = new QSpinBox(this);

    breakSpin = new QSpinBox(this);

    submitButton = new QPushButton("Set changes", this);

    longBreakLabel = new QLabel("Long break", this);

    longBreakSpin = new QSpinBox(this);
    longBreakSpin->setValue(15);

    historyCombo = new QComboBox(this);
    historyCombo->addItem("None");
    historyCombo->addItem("Today");
    historyCombo->addItem("All");

    historyLabel = new QLabel("History settings: ");

    pomodoroSpin->setValue(25);
    breakSpin->setValue(5);

    pomodoroTimeLayout->addWidget(timeLabel);
    pomodoroTimeLayout->addWidget(pomodoroSpin);

    breakTimeLayout->addWidget(breakLabel);
    breakTimeLayout->addWidget(breakSpin);

    longBreakLayout->addWidget(longBreakLabel);
    longBreakLayout->addWidget(longBreakSpin);

    historyLayout->addWidget(historyLabel);
    historyLayout->addWidget(historyCombo);

    centralLayout->addLayout(pomodoroTimeLayout);
    centralLayout->addLayout(breakTimeLayout);
    centralLayout->addLayout(longBreakLayout);
    centralLayout->addLayout(historyLayout);
    centralLayout->addWidget(submitButton);

    connect(submitButton, SIGNAL(clicked()), this, SLOT(MakeChanges()));

    Qt::WindowFlags flags = Qt::Window
                                | Qt::WindowMinimizeButtonHint
                                | Qt::WindowCloseButtonHint;

    setWindowFlags(flags);
}

void SettingsDialog::MakeChanges()
{
    QSettings settings("nescode", "ParadajzApp");

    settings.setValue("Pomodoro", pomodoroSpin->value());
    settings.setValue("Break", breakSpin->value());
    settings.setValue("Fourth Pomodoro", longBreakSpin->value());
    settings.setValue("History", historyCombo->currentIndex());

    emit Changed();

    this->close();
}


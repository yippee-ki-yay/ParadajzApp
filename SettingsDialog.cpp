#include "SettingsDialog.h"

SettingsDialog::SettingsDialog(QWidget* parent): QDialog(parent)
{
    centralLayout = new QVBoxLayout(this);

    pomodoroTimeLayout = new QHBoxLayout;

    breakTimeLayout = new QHBoxLayout;

    timeLabel = new QLabel("Change Pomodoro time", this);

    breakLabel = new QLabel("Change break time", this);

    pomodoroSpin = new QSpinBox(this);

    breakSpin = new QSpinBox(this);

    submitButton = new QPushButton("Set changes", this);

    pomodoroSpin->setValue(25);
    breakSpin->setValue(5);

    pomodoroTimeLayout->addWidget(timeLabel);
    pomodoroTimeLayout->addWidget(pomodoroSpin);

    breakTimeLayout->addWidget(breakLabel);
    breakTimeLayout->addWidget(breakSpin);

    centralLayout->addLayout(pomodoroTimeLayout);
    centralLayout->addLayout(breakTimeLayout);
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

    emit Changed();

    this->close();
}


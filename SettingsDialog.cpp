#include "SettingsDialog.h"

SettingsDialog::SettingsDialog(QWidget* parent): QDialog(parent)
{
    centralLayout = new QVBoxLayout(this);

    timeLayout = new QHBoxLayout(this);

    timeLabel = new QLabel("Change Time", this);

    timeLayout->addWidget(timeLabel);

    centralLayout->addLayout(timeLayout);

    Qt::WindowFlags flags = Qt::Window
                                | Qt::WindowMinimizeButtonHint
                                | Qt::WindowCloseButtonHint;

    setLayout(centralLayout);
    setWindowFlags(flags);
}


void SettingsDialog::SetFile(QFile* settings)
{
    QTextStream txtStream(settings);
    txtStream << "yes";
}

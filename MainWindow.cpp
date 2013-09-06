#include "MainWindow.h"


MainWindow::MainWindow(QWidget* parent): QMainWindow(parent)
{

    QWidget* centralWidget = new QWidget;

    SetButtons();

    centralLayout = new QVBoxLayout;

    timer = new Timer(centralWidget);

    historyList = new QListWidget(centralWidget);

    centralLayout->addWidget(timer);
    centralLayout->addLayout(buttonLayout);
    centralLayout->addWidget(historyList);

    connect(startButton, SIGNAL(clicked()), timer, SLOT(StartPomodoro()));
    connect(pauseButton, SIGNAL(clicked()), timer, SLOT(Pause()));
    connect(breakButton, SIGNAL(clicked()), timer, SLOT(StartBreak()));


    setCentralWidget(centralWidget);

    centralWidget->setLayout(centralLayout);
}

void MainWindow::SetButtons()
{
    buttonLayout = new QHBoxLayout;

    startButton = new QPushButton("Start");
    pauseButton = new QPushButton("Pause");
    breakButton = new QPushButton("Break");

    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(pauseButton);
    buttonLayout->addWidget(breakButton);

}

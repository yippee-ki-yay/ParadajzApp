#include "MainWindow.h"


MainWindow::MainWindow(QWidget* parent): QMainWindow(parent)
{

    QWidget* centralWidget = new QWidget;

    SetButtons();

    centralLayout = new QVBoxLayout;

    timer = new Timer(centralWidget);

    historyList = new QListWidget(centralWidget);

    historyFile = new QFile("history.txt", centralWidget);

    historyFile->open(QFile::Text | QFile::Append);

    historyStream = new QTextStream(historyFile);

    centralLayout->addWidget(timer);
    centralLayout->addLayout(buttonLayout);
    centralLayout->addWidget(historyList);

    connect(startButton, SIGNAL(clicked()), timer, SLOT(StartPomodoro()));
    connect(pauseButton, SIGNAL(clicked()), timer, SLOT(Pause()));
    connect(breakButton, SIGNAL(clicked()), timer, SLOT(StartBreak()));
    connect(timer, SIGNAL(FinishedPomodoro()), this, SLOT(AddToFile()));


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

void MainWindow::AddToFile()
{

    QString pomodoroStr = "Pomodoro finished  ";
    QDateTime currDate = QDateTime::currentDateTime();
    QString dateStr = currDate.toString("dd.MM.yy  hh:mm");

    historyList->addItem(pomodoroStr + dateStr);

    *historyStream << pomodoroStr << dateStr << "\n";
}

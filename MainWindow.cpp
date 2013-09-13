#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent)
{

    Init();

    SetUi();

    LoadHistory();

    SetConnections();

}

MainWindow::~MainWindow()
{
    historyFile->close();
    readHistoryFile->close();

}

/*This is horrible need to organize my code*/

void MainWindow::Init()
{
    centralWidget = new QWidget;

    settingsDialog = new SettingsDialog(centralWidget);

    dingMedia = Phonon::createPlayer(Phonon::MusicCategory,
                                     Phonon::MediaSource("bell-ring.mp3"));

    gearPix = new QPixmap("gear.png");

    settings = new QSettings("nescode", "ParadajzApp");

    settingsAction = new QAction(*gearPix, "&Settings", centralWidget);

    quitAction = new QAction("Quit", centralWidget);

    settingsMenu = menuBar()->addMenu("&Pomodoro");
    settingsMenu->addAction(settingsAction);
    settingsMenu->addAction(quitAction);

    centralLayout = new QVBoxLayout;

    timer = new Timer(centralWidget);

    ReadSettings();

    historyList = new QListWidget(centralWidget);

    historyFile = new QFile("history.txt", centralWidget);

    readHistoryFile = new QFile("history.txt", centralWidget);

    readHistoryFile->open(QFile::ReadOnly);

    historyFile->open(QFile::Text | QFile::Append | QFile::ReadWrite);

    historyStream = new QTextStream(historyFile);

    buttonLayout = new QHBoxLayout;

    startButton = new QPushButton("Start");
    pauseButton = new QPushButton("Pause");
    breakButton = new QPushButton("Break");

}

void MainWindow::SetUi()
{

    centralLayout->addWidget(timer);
    centralLayout->addLayout(buttonLayout);
    centralLayout->addWidget(historyList);

    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(pauseButton);
    buttonLayout->addWidget(breakButton);

    setCentralWidget(centralWidget);

    centralWidget->setLayout(centralLayout);
}

void MainWindow::SetConnections()
{
    connect(startButton, SIGNAL(clicked()), timer, SLOT(StartPomodoro()));
    connect(pauseButton, SIGNAL(clicked()), timer, SLOT(Pause()));
    connect(breakButton, SIGNAL(clicked()), timer, SLOT(StartBreak()));
    connect(timer, SIGNAL(FinishedPomodoro()), this, SLOT(AddToFile()));
    connect(timer, SIGNAL(FinishedBreak()), this, SLOT(AlertForBreak()));

    connect(settingsAction, SIGNAL(triggered()), settingsDialog, SLOT(show()));
    connect(settingsDialog, SIGNAL(Changed()), this, SLOT(ReadSettings()));

    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
}


void MainWindow::AddToFile()
{
    dingMedia->play();

    QString pomodoroStr = "Pomodoro finished  ";
    QDateTime currDate = QDateTime::currentDateTime();
    QString dateStr = currDate.toString("dd.MM.yy  hh:mm");

    historyList->insertItem(0, pomodoroStr + dateStr);

    *historyStream << pomodoroStr << dateStr << "\n";
}

void MainWindow::AlertForBreak()
{
    dingMedia->play();
}

void MainWindow::ReadSettings()
{
   p = settings->value("Pomodoro").toInt();
   b = settings->value("Break").toInt();

   timer->setTime(p, b);
}

void MainWindow::LoadHistory()
{
    QTextStream loadEntries(readHistoryFile);

    //Load just todays pomodoros
    QString tmp;

    QDateTime currDate = QDateTime::currentDateTime();
    QString yeah = currDate.toString("dd.MM.yy");

    while(!loadEntries.atEnd())
    {
        tmp = loadEntries.readLine();
        tmp.contains(yeah);

        if(tmp.contains(yeah))
        {
            historyList->addItem(tmp);
        }

    }

/*
    //reads all history
    while(!loadEntries.atEnd())
    {
        historyList->addItem(loadEntries.readLine());
    }*/

}

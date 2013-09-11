#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>  //FOR TESTING REMOVE
#include <QDebug>

#include <phonon/MediaObject>

#include <QMainWindow>
#include <QWidget>

#include <QDateTime>
#include <QStringList>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "Timer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();

public slots:
    void AddToFile();
    void AlertForBreak();

private:
    void LoadHistory();

    void Init();
    void SetConnections();
    void SetUi();

    Phonon::MediaObject* dingMedia;

    QWidget* centralWidget;
    QMenu* settingsMenu;
    QMenuBar* bar;
    QAction* settingsAction;
    QAction* quitAction;

    Timer* timer;
    QFile* historyFile;
    QFile* readHistoryFile;
    QTextStream* historyStream;

    QListWidget* historyList;
    QStringList* historyStrList;

    QVBoxLayout* centralLayout;
    QHBoxLayout* buttonLayout;

    QPushButton* startButton;
    QPushButton* pauseButton;
    QPushButton* breakButton;

    QPixmap* gearPix;

};

#endif // MAINWINDOW_H

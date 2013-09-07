#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>  //FOR TESTING REMOVE

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

#include "Timer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);

public slots:
    void AddToFile();

private:
    void SetButtons();

    Timer* timer;
    QFile* historyFile;
    QTextStream* historyStream;

    QListWidget* historyList;
    QStringList* historyStrList;

    QVBoxLayout* centralLayout;
    QHBoxLayout* buttonLayout;

    QPushButton* startButton;
    QPushButton* pauseButton;
    QPushButton* breakButton;

};

#endif // MAINWINDOW_H

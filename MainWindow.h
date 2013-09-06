#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "Timer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
private:
    void SetButtons();

    Timer* timer;

    QListWidget* historyList;

    QVBoxLayout* centralLayout;
    QHBoxLayout* buttonLayout;

    QPushButton* startButton;
    QPushButton* pauseButton;
    QPushButton* breakButton;

};

#endif // MAINWINDOW_H

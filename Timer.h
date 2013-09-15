#ifndef TIMER_H
#define TIMER_H

#include <iostream>   //TESTING REMOVE

#include <QLCDNumber>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>
#include <QString>
#include <QSettings>

class Timer : public QLCDNumber
{
    Q_OBJECT

public:
    Timer(QWidget* parent = 0);

    enum state{POMODORO, BREAK, NONE};

    void setTime(int p, int b);

public slots:
    void StartPomodoro();
    void StartBreak();
    void Pause();

private slots:
    void Count();

signals:
    void FinishedPomodoro();
    void FinishedBreak();

private:
    void ButtonBox();

    QTimer* timer;


    QMessageBox* fourthMessageBox;
    QPushButton* longBreakButton;
    QPushButton* shortBreakButton;

    int minut, second;
    int m_p, m_b;
    bool running;
    state curr_state;
    int pomodoro_count;
};

#endif // TIMER_H

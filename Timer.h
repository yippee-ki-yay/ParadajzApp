#ifndef TIMER_H
#define TIMER_H

#include <iostream>   //TESTING REMOVE

#include <QLCDNumber>
#include <QTimer>
#include <QString>

class Timer : public QLCDNumber
{
    Q_OBJECT

public:
    Timer(QWidget* parent = 0);

    enum state{POMODORO, BREAK, NONE};

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
    QTimer* timer;

    int minut, second;
    bool running;
    state curr_state;
};

#endif // TIMER_H

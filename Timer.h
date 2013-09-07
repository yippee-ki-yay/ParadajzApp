#ifndef TIMER_H
#define TIMER_H

#include <QLCDNumber>
#include <QTimer>
#include <QString>

class Timer : public QLCDNumber
{
    Q_OBJECT

public:
    Timer(QWidget* parent = 0);

public slots:
    void StartPomodoro();
    void StartBreak();
    void Pause();

private slots:
    void Count();

signals:
    void FinishedPomodoro();

private:
    QTimer* timer;

    int minut, second;
    bool running;
};

#endif // TIMER_H

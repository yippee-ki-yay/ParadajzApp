#include "Timer.h"

Timer::Timer(QWidget* parent) : QLCDNumber(parent), minut(0), second(0), running(false)
{
    timer = new QTimer(this);

    display("00:00");
}

void Timer::StartPomodoro()
{
    minut = 24;
    second = 59;

    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(Count()));
}

void Timer::StartBreak()
{
    minut = 4;
    second = 59;

    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(Count()));
}

void Timer::Pause()
{

}

void Timer::Count()
{

    //if we reaches 00:00 end timer
    if(minut == 0 && second == 0)
    {
        timer->stop();
    }

    //convert num to str for displaying on timer

    QString minutStr = QString::number(minut);
    QString secondStr = QString::number(second);

    QString timeStr = minutStr + ":" + secondStr;

    second--;

    //for proper displaying, when single digit set a 0 in front

    if(second < 9)
        timeStr = minutStr + ":0" + secondStr;

    if(minut < 10)
    {
        timeStr = "0" + minutStr +":" + secondStr;

        if(second < 9)
            timeStr = "0" + minutStr +":0" + secondStr;
    }

    //when 60s passed, one minute less
    if(second == 0 && minut != 0)
    {
        second = 59;
        minut--;
    }

    display(timeStr);

}

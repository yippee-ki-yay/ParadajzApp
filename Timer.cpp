#include "Timer.h"

Timer::Timer(QWidget* parent) : QLCDNumber(parent), minut(0), second(0), running(false),
    curr_state(NONE)
{
    timer = new QTimer(this);
    timer->setInterval(1000);

    setSegmentStyle(QLCDNumber::Filled);

    display("00:00");

    setMinimumSize(400, 200);
}

void Timer::setTime(int p, int b)
{
    m_p = p;
    m_b = b;
}

void Timer::StartPomodoro()
{
    running = true;
    curr_state = POMODORO;

    minut = m_p - 1;
    second = 59;

    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(Count()), Qt::UniqueConnection);
}

void Timer::StartBreak()
{
    running = true;

    curr_state = BREAK;

    minut = m_b - 1;
    second = 59;

    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(Count()), Qt::UniqueConnection);
}

void Timer::Pause()
{
    if(running)
    {
        timer->stop();
        running = false;
    }
    else
    {
        timer->start();
        running = true;
    }
}

void Timer::Count()
{

    //if we reaches 00:00 end timer
    if(minut == 0 && second <= 0)
    {
        timer->stop();


        if(curr_state == POMODORO)
            emit FinishedPomodoro();
        if(curr_state == BREAK)
            emit FinishedBreak();
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

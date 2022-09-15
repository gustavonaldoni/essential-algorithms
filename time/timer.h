typedef struct
{
    float initialSeconds;
    float currentSeconds;
} Timer;

Timer TimerCreate(float);
void TimerReset(Timer *);
bool TimerIsDone(Timer);
void TimerUpdate(Timer *);

Timer TimerCreate(float initialSeconds)
{
    Timer timer;

    timer.currentSeconds = initialSeconds;
    timer.initialSeconds = initialSeconds;

    return timer;
}

void TimerReset(Timer *timer)
{
    timer->currentSeconds = timer->initialSeconds;
}

bool TimerIsDone(Timer timer)
{
    return timer.currentSeconds <= 0.0f;
}

void TimerUpdate(Timer *timer)
{
    if (!TimerIsDone(*timer))
    {
        timer->currentSeconds -= GetFrameTime();
    }
}

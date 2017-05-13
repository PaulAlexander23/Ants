#pragma once

#include "Header1.h"

class Timer
{
public:
    Timer(Uint32 interval);
    ~Timer();
    bool StartTimer();
    bool StopTimer();
    bool ToggleTimer();
private:
    static Uint32 my_callbackfunc(Uint32 interval, void *param);
    Uint32 delay;
    int param;
    SDL_TimerID my_timer_id;
    bool running;
};

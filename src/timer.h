#pragma once

#include "main.h"

class timer
{
public:
    timer(Uint32 interval);
    ~timer();
    bool start();
    bool stop();
    bool toggle();
private:
    static Uint32 my_callbackfunc(Uint32 interval, void *param);
    Uint32 delay;
    int param;
    SDL_TimerID my_timer_id;
    bool running;
};

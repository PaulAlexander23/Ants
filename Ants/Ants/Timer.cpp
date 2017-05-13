#include "Timer.h"

Timer::Timer(Uint32 interval)
{
    delay = interval;
    param = 0;
    //Uint32 USER_TIMER = SDL_RegisterEvents(1);
    running = false;
    //my_timer_id = SDL_AddTimer(delay, my_callbackfunc, &param);
}

Timer::~Timer()
{
    if(running)
    {
        StopTimer();
    }
}

Uint32 Timer::my_callbackfunc(Uint32 interval, void *refparam)
{
    SDL_Event event;
    SDL_UserEvent userevent;

    /* In this example, our callback pushes an SDL_USEREVENT event
    into the queue, and causes our callback to be called again at the
    same interval: */

    std::cout<<"tick\n";

    userevent.type = SDL_USEREVENT;
    userevent.code = 0;
    userevent.data1 = NULL;
    userevent.data2 = NULL;

    event.type = SDL_USEREVENT;
    event.user = userevent;

    SDL_PushEvent(&event);
    return(interval);
}

bool Timer::StartTimer()
{
    if(!running)
    {
        my_timer_id = SDL_AddTimer(delay, my_callbackfunc, &param);
        running = true;
        return true;
    }
    return false;
}

bool Timer::StopTimer()
{
    if(running)
    {
        running = false;
        return SDL_RemoveTimer(my_timer_id);
    }
    return false;
}

bool Timer::ToggleTimer()
{
    if(running)
    {
        return StopTimer();
    }
    else
    {
        return StartTimer();
    }
}

/*
 * TimerObserver.cpp
 */

#include "../../new_version/src/TimerSysObserver.hpp"

TimerSysObserver::TimerSysObserver() {

}

TimerSysObserver::~TimerSysObserver() {

}




//https://wiki.libsdl.org/SDL_AddTimer?highlight=%28%5CbCategoryTimer%5Cb%29%7C%28CategoryEnum%29%7C%28CategoryStruc%29

#if 0
Code Examples



Toggle line numbers /* Start the timer; the callback below will be executed after the delay */

Uint32 delay = (33 / 10) * 10;  /* To round it down to the nearest 10 ms */
SDL_TimerID my_timer_id = SDL_AddTimer(delay, my_callbackfunc, my_callback_param);

...

Uint32 my_callbackfunc(Uint32 interval, void *param)
{
    SDL_Event event;
    SDL_UserEvent userevent;

    /* In this example, our callback pushes an SDL_USEREVENT event
    into the queue, and causes our callback to be called again at the
    same interval: */

    userevent.type = SDL_USEREVENT;
    userevent.code = 0;
    userevent.data1 = NULL;
    userevent.data2 = NULL;

    event.type = SDL_USEREVENT;
    event.user = userevent;

    SDL_PushEvent(&event);
    return(interval);
}


Note that it is possible to avoid the multithreading problems with SDL timers by giving to userevent.data1 the address of a function you want to be executed and to userevent.data2 its params, and then deal with it in the event loop.

Toggle line numbers /* with the same code as before: */
Uint32 my_callbackfunc(Uint32 interval, void *param)
{
    SDL_Event event;
    SDL_UserEvent userevent;

    /* In this example, our callback pushes a function
    into the queue, and causes our callback to be called again at the
    same interval: */

    userevent.type = SDL_USEREVENT;
    userevent.code = 0;
    userevent.data1 = &my_function;
    userevent.data2 = param;

    event.type = SDL_USEREVENT;
    event.user = userevent;

    SDL_PushEvent(&event);
    return(interval);
}

/* Now the event loop */
SDL_Event event;
while (SDL_PollEvent (&event))
{
    switch(event.type)
    {
        case SDL_USEREVENT: {
            /* and now we can call the function we wanted to call in the timer but couldn't because of the multithreading problems */
            void (*p) (void*) = event.user.data1;
            p(event.user.data2);
            break;
        }
        /* ... */
    }
}




Remarks

If you use this function, you must pass SDL_INIT_TIMER to SDL_Init().

The callback function is passed the current timer interval and the user supplied parameter from the SDL_AddTimer() call and returns the next timer interval. If the returned value from the callback is 0, the timer is canceled.

The callback is run on a separate thread. See the code examples for a method of processing the timer callbacks on the main thread if that's desired.

#endif

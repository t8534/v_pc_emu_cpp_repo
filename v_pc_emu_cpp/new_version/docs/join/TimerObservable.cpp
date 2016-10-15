/*
 * Timer.cpp
 *
 */

#include "../../../new_version/docs/join/TimerObservable.hpp"

#include <iostream>
#include <set>


TimerObservable* TimerObservable::instance = NULL;

TimerObservable* TimerObservable::GetInstance()
{
    if ( instance == NULL ) {
       instance = new TimerObservable();
    }

    return instance;
}

void TimerObservable::AddObserver(TimerObserver& o)
{
    observers.insert(&o);
}

void TimerObservable::RemoveObserver(TimerObserver& o)
{
    observers.erase(&o);
}

void TimerObservable::NotifyObservers()
{
    std::set<TimerObserver*>::iterator itr;
    for ( itr = observers.begin();
          itr != observers.end(); itr++ )
    (*itr)->Notify();
}

// TEST METHOD TO TRIGGER
// IN THE REAL SCENARIO THIS IS NOT REQUIRED
void TimerObservable::Trigger()
{
    NotifyObservers();
}




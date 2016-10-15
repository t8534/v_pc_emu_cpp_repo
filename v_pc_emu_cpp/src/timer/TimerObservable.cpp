/*
 * Timer.cpp
 *
 *  Created on: Jun 15, 2016
 *      Author: liberdaa
 */

#include <iostream>
#include <set>
#include "TimerObservable.hpp"


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




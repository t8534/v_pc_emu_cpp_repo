/*
 * Timer.hpp
 *
 */

#ifndef TIMEROBSERVABLE_HPP_
#define TIMEROBSERVABLE_HPP_

#include <set>

#include "../../../new_version/docs/join/TimerObserver.hpp"


class TimerObservable
{

	static TimerObservable* instance;
    std::set<TimerObserver*> observers;
    TimerObservable() { };

	public:
       static TimerObservable* GetInstance();
       void AddObserver(TimerObserver& o);
       void RemoveObserver(TimerObserver& o);
       void NotifyObservers();
       void Trigger();
};



#endif /* TIMEROBSERVABLE_HPP_ */

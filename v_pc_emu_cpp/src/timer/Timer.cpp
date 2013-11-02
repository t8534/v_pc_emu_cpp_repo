/*
 * Timer.cpp
 *
 *  Created on: 20-06-2012
 *      Author: liberdaa
 */


#include <list>
#include <algorithm>
#include "Timer.h"


// system timer
//#include <windows.h>


namespace Vario {


Timer::Timer(uint32_t period = 0) : period(period)
{
	//      Sleep( sometime_in_millisecs );   // note uppercase S
}


Timer::~Timer()
{

}


void Timer::addListener(TimerListener* listener)
{
	//todo any exception if wrong ?
	listenerList.push_back(listener);
}


void Timer::removeListener(TimerListener* listener)
{
	std::list<TimerListener*>::iterator pos;
	pos = std::find(listenerList.begin(), listenerList.end(), listener);
	if (pos != listenerList.end()) {
		listenerList.erase(pos);
	}
}


void Timer::set(uint32_t period)
{
	this->period = period;
}


void Timer::start()
{

}


void Timer::stop()
{


}


uint32_t Timer::getElapsedTime()
{

	uint32_t res = 0;

	return res;
}


void Timer::fireEvent()
{

	// EventObject e;
	// iterate call timerEventHandler(EventObject e);

	std::list<TimerListener*>::const_iterator pos = listenerList.begin();
	while (pos != listenerList.end())
	{
	   (*pos)->timerEventHandler();
	   pos++;
	}

}


// todo: remove after tests
//debug
// Call fireEvent
void Timer::debugCallFireEvent()
{
	fireEvent();
}


}   // namespace

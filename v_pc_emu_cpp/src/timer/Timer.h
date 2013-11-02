/*
 * Timer.h
 *
 *  Created on: 20-06-2012
 *      Author: liberdaa
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <list>
#include <stdint.h>
#include "TimerListener.h"


namespace Vario {

class Timer
{

	public:

		Timer(uint32_t period);
		virtual ~Timer();


		void addListener(TimerListener* listener);
		void removeListener(TimerListener* listener);

		void set(uint32_t period);

		void start();

		void stop();

		uint32_t getElapsedTime();


		// todo: remove after tests
		//debug
		// Call fireEvent
		void debugCallFireEvent();

	private:
		uint32_t period;
		std::list<TimerListener*> listenerList;

		void fireEvent();

};


} // End of namespace Vario

#endif /* TIMER_H_ */

/*
 * TimerListener.h
 *
 *  Created on: 20-06-2012
 *      Author: liberdaa
 */

#ifndef TIMERLISTENER_H_
#define TIMERLISTENER_H_


namespace Vario {

// Interface
class TimerListener
{
	public:
		virtual ~TimerListener() {};
		virtual void timerEventHandler() = 0;

	protected:
		TimerListener() {};
};


} // End of namespace Vario

#endif /* TIMERLISTENER_H_ */

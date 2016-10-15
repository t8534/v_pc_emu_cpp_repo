/*
 * TimerObserver.hpp
 *
 *  Created on: Jun 15, 2016
 *      Author: liberdaa
 */

#ifndef TIMEROBSERVER_HPP_
#define TIMEROBSERVER_HPP_


class TimerObserver
{
    public:
	    TimerObserver();
	    virtual ~TimerObserver();
        virtual void Notify() = 0;


};



#endif /* TIMEROBSERVER_HPP_ */

/*
 * TriggeredObj.hpp
 *
 *  Created on: Jun 30, 2016
 *      Author: liberdaa
 */

#ifndef TRIGGEREDOBJ_HPP_
#define TRIGGEREDOBJ_HPP_

#include "../../../new_version/docs/join/TimerObservable.hpp"
#include "../../../new_version/docs/join/TimerObserver.hpp"



class TriggeredObj : public TimerObserver {

	TimerObservable* observable;

    public:
	TriggeredObj() {
          observable = TimerObservable::GetInstance();
          observable->AddObserver(*this);
       }

       ~TriggeredObj() {
          observable->RemoveObserver(*this);
       }

       void Notify() {
            std::cout << "Received a change event" << endl;
       }
};



#endif /* TRIGGEREDOBJ_HPP_ */

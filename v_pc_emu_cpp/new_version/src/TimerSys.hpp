/*
 * TimerSys.hpp
 */

#ifndef SRC_TIMERSYS_HPP_
#define SRC_TIMERSYS_HPP_

#include <set>

#include "../../new_version/src/TimerSysObserver.hpp"


class TimerSys {
public:
	TimerSys();
	virtual ~TimerSys();

	TimerSys* GetInstance();
	void AddObserver(TimerSysObserver*);
	void RemoveObserver(TimerSysObserver*);
	void Start();
	void Stop();

private:
	TimerSys* instance;
	bool state;
	std::set<TimerSysObserver*> observers;

};

#endif /* SRC_TIMERSYS_HPP_ */

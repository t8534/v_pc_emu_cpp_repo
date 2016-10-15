//============================================================================
// Name        : vcpp.cpp
//============================================================================



#include <iostream>

#include "../../../new_version/docs/join/TimerObservable.hpp"
#include "../../../new_version/docs/join/TimerObserver.hpp"
#include "../../../new_version/docs/join/TriggeredObj.hpp"


using namespace std;

int main() {

	cout << "Start" << endl;

	TimerObservable* observable = TimerObservable::GetInstance();
	TriggeredObj* obj = new TriggeredObj();
	observable->Trigger();



	return 0;
}

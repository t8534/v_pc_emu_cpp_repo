//
// v_pc.cpp

//
//
// v.130824_0944
//
//
// todo:
// 1.Check new makefile
//



#include <iostream>

#include "Timer.h"
#include "DisplaySDL.h"
#include "BMP085Sensor.h"

// system timer
#include <windows.h>


//debug
#include "TimerListener.h"


//using namespace Vario;  // todo problem

int main() {

	Vario::Timer timerMain(12);
	Vario::DisplaySDL displaySDL;
	Vario::BMP085Sensor sensorBMP085;

	std::cout << "Well... let's start" << std::endl;


	timerMain.addListener(&sensorBMP085);

	int cnt = 0;
	while (1) {



		Sleep(1000);   // note uppercase S
		std::cout << "Every second... call Timer fireEvent(). cnt = " << cnt << std::endl;
		timerMain.debugCallFireEvent();

		// After 10 passes add DisplaySDL listener
		if (10 == cnt) {
			std::cout << "### timerMain.addListener(&displaySDL). cnt = " << cnt << std::endl;
			timerMain.addListener(&displaySDL);
		}

		// After 20 passes remove SensorBMP085 listener
		if (20 == cnt) {
			std::cout << "### timerMain.removeListener(&sensorBMP085). cnt = " << cnt << std::endl;
			timerMain.removeListener(&sensorBMP085);
		}

		// After 30 passes remove DisplaySDL listener
		if (30 == cnt) {
			std::cout << "### timerMain.removeListener(&displaySDL). cnt = " << cnt << std::endl;
			timerMain.removeListener(&displaySDL);
		}

		// After 50 passes stop
		if (50 == cnt) {
			std::cout << "END" << std::endl;
			break;
		}

		cnt++;
	}


	return 0;
}

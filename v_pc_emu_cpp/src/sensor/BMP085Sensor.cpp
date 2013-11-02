/*
 * BMP085Sensor.cpp
 *
 *  Created on: 20-06-2012
 *      Author: liberdaa
 */

#include "Sensor.h"
#include "BMP085Sensor.h"

//debug
#include <iostream>


namespace Vario {

BMP085Sensor::BMP085Sensor()
{
	//todo: add itself to the Timer listener, from here
}

BMP085Sensor::~BMP085Sensor()
{

}



uint16_t BMP085Sensor::getPressure()
{
	return 0;
}


uint16_t BMP085Sensor::getTemperature()
{
	return 0;
}


void BMP085Sensor::reset()
{

}


void BMP085Sensor::timerEventHandler()
{

	std::cout << "BMP085Sensor::timerEventHandler() was called." << std::endl;

}


} // namespace Vario

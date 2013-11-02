/*
 * BMP085Sensor.h
 *
 *  Created on: 20-06-2012
 *      Author: liberdaa
 */

#ifndef BMP085SENSOR_H_
#define BMP085SENSOR_H_


#include <stdint.h>
#include "Sensor.h"


namespace Vario {

class BMP085Sensor: public Sensor
{

public:
	BMP085Sensor();
	virtual ~BMP085Sensor();

	uint16_t getPressure();
	uint16_t getTemperature();
	void reset();
	void timerEventHandler();


};


}  // namespace Vario

#endif /* BMP085SENSOR_H_ */

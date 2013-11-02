/*
 * Sensor.h
 *
 *  Created on: 20-06-2012
 *      Author: liberdaa
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include <stdint.h>
#include "TimerListener.h"

// This is abstract class for sensors.
// TODO:
// 1.
// Throw exception from Constructor if sensor communication error.
// Also when reset() and for all read functions.
//
// 2.
// Maybe open() and close() ?

namespace Vario {


// Interface
class Sensor : public TimerListener
{

public:

	virtual ~Sensor() {};

	virtual void timerEventHandler() = 0;
	virtual uint16_t getPressure() = 0;
	virtual uint16_t getTemperature() = 0;
	virtual void reset() = 0;

protected:

	Sensor() {};

};


} // End of namespace Vario

#endif /* SENSOR_H_ */

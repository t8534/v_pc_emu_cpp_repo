/*
 * Display.h
 *
 * TODO:
 *
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <string>
#include <stdint.h>
#include "TimerListener.h"

namespace Vario {

class Display : public TimerListener
{

public:

	virtual ~Display();

	virtual void open() = 0;
	virtual void close() = 0;

	virtual void timerEventHandler() = 0;

	virtual void writeTextAt(const std::string s) const = 0;
	virtual void setPixel() = 0;
	virtual void clearPixel() = 0;
	virtual void drawLine() = 0;
	virtual void drawRectangle() = 0;
	virtual void drawCircle() = 0;

protected:

	uint16_t width;
	uint16_t height;

	Display(uint16_t w, uint16_t h);

};


} // End of namespace Vario

#endif /* DISPLAY_H_ */

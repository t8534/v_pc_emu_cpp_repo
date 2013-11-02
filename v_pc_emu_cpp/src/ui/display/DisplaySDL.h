/*
 * DisplaySDL.h
 *
 *  Created on: 19-08-2013
 *      Author: arek
 */

#ifndef DISPLAYSDL_H_
#define DISPLAYSDL_H_


#include "Display.h"

namespace Vario {

class DisplaySDL : public Display
{

public:


	DisplaySDL(uint16_t w = 800, uint16_t h = 600);
	virtual ~DisplaySDL();


	void open();
	void close();

	void timerEventHandler();

	void writeTextAt(const std::string s) const;
	void setPixel();
	void clearPixel();
	void drawLine();
	void drawRectangle();
	void drawCircle();

};


} // namespace Vario

#endif /* DISPLAYSDL_H_ */

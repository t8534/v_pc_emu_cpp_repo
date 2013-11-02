/*
 * DisplaySDL.cpp
 *
 *  Created on: 19-08-2013
 *      Author: arek
 */

#include <iostream>
#include "DisplaySDL.h"

namespace Vario {

DisplaySDL::DisplaySDL(uint16_t w, uint16_t h) : Display(w, h)
{

	//todo: add itself to the Timer listener, from here
}


DisplaySDL::~DisplaySDL()
{

}


void DisplaySDL::open()
{

}


void DisplaySDL::close()
{

}


void DisplaySDL::timerEventHandler()
{

	std::cout << "DisplaySDL::timerEventHandler() was called." << std::endl;

}


void DisplaySDL::writeTextAt(const std::string s) const
{

}


void DisplaySDL::setPixel()
{

}


void DisplaySDL::clearPixel()
{

}


void DisplaySDL::drawLine()
{

}


void DisplaySDL::drawRectangle()
{

}


void DisplaySDL::drawCircle()
{

}


} /* namespace Vario */

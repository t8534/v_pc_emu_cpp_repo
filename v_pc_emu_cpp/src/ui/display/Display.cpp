/*
 * Display.cpp
 *
 *  Created on: 30-07-2013
 *      Author: liberdaa
 */

#include "Display.h"

//debug
#include <iostream>


namespace Vario {


Display::Display(uint16_t w, uint16_t h) : width(w), height(h)
{

}


Display::~Display()
{

}



void Display::timerEventHandler()
{

	std::cout << "Display::timerEventHandler() was called." << std::endl;

}


} // End of namespace Vario.

#ifndef _BUTTON_H
#define _BUTTON_H

#include "cprocessing.h"

struct Button
{
	const char* text;
	float x, y, width, height;
	CP_Color FontC, DefaultC, HoverC;
};


#endif

#ifndef _BUTTON_H
#define _BUTTON_H

#include "cprocessing.h"
#include <stdbool.h>

struct Button
{
	const char* text;
	float x, y, width, height;
	CP_Color FontC, DefaultC, HoverC;
};

bool Button_IsHover(struct Button* button);


#endif

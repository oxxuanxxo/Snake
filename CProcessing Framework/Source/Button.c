#include "Button.h"
#include <stdbool.h>

bool Button_IsHover(struct Button* button)
{
	if (
		(CP_Input_GetMouseX() >= button->x - button->width * 0.5f) &&
		(CP_Input_GetMouseX() <= button->x + button->width * 0.5f) &&
		(CP_Input_GetMouseY() >= button->y - button->height * 0.5f) &&
		(CP_Input_GetMouseY() <= button->y + button->height * 0.5f)
		)
	{
		return true;
	}
	return false;
}
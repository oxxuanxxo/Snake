#include "Button.h"
#include <stdbool.h>

/* !
@file       Button.c
@author     Wu Pei Fang(peifang.w)
@brief      Work the button
*//*__________________________________________________________________________*/
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

void RenderButton(struct Button* button)
{
	CP_Settings_Fill(button->DefaultC);
	if (Button_IsHover(button) == true)
	{
		CP_Settings_Fill(button->HoverC);
	}
	CP_Graphics_DrawRect(button->x - button->width * 0.5f, button->y - button->height * 0.5f, button->width, button->height);
	CP_Settings_Fill(button->FontC);
	CP_Font_DrawText(button->text, button->x, button->y);
}

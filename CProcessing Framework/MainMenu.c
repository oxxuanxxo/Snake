#include "MainMenu.h"
#include "cprocessing.h"
#include "Snake/Snake.h"




void Play_OnClick(void)
{
	CP_Engine_SetNextGameState(Snake_init, Snake_update, Snake_exit);
}


void MainMenu_Init()
{
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
	struct Button p = {
		.text = "Play",
		.x = (float)CP_System_GetWindowWidth() / 2,
		.y = (float)CP_System_GetWindowHeight() / 3,
		.width = 200,
		.height = 100,
		.colorFont = CP_Color_Create(0, 0, 0, 255),
		.colorDefault = CP_Color_Create(255, 255, 255, 255),
		.colorHover = CP_Color_Create(255, 64, 64, 255),
		.onClick = &Play_OnClick,
	};
	play = p;

	struct Button q = {
		.text = "Quit",
		.x = (float)CP_System_GetWindowWidth() / 2,
		.y = (float)CP_System_GetWindowHeight() * 2 / 3,
		.width = 200,
		.height = 100,
		.colorFont = CP_Color_Create(0, 0, 0, 255),
		.colorDefault = CP_Color_Create(255, 255, 255, 255),
		.colorHover = CP_Color_Create(255, 64, 64, 255),
		.onClick = &Play_OnClick,
	};
	quit = q;

}

void MainMenu_Update()
{
	float mouseX = CP_Input_GetMouseX(), mouseY = CP_Input_GetMouseY();

	CP_Settings_Background(CP_Color_Create(128, 128, 128, 255));

	if (play.x - play.width / 2 < mouseX && mouseX < play.x + play.width / 2 && play.y - play.height / 2 < mouseY && mouseY < play.y + play.height / 2)
	{
		CP_Settings_Fill(play.colorHover);
		if (CP_Input_MouseClicked())
		{
			play.onClick();
		}
	}

	else
	{
		CP_Settings_Fill(play.colorDefault);
	}
	CP_Graphics_DrawRect(play.x - play.width / 2, play.y - play.height / 2, play.width, play.height);
	CP_Settings_Fill(play.colorFont);
	CP_Font_DrawText(play.text, play.x, play.y);
	

	if (quit.x - quit.width / 2 < mouseX && mouseX < quit.x + quit.width / 2 && quit.y - quit.height / 2 < mouseY && mouseY < quit.y + quit.height / 2)
	{
		CP_Settings_Fill(quit.colorHover);
		if (CP_Input_MouseClicked())
		{
			CP_Engine_Terminate();
		}
	}
	else
	{
		CP_Settings_Fill(quit.colorDefault);
	}
	CP_Graphics_DrawRect(quit.x - quit.width / 2, quit.y - quit.height / 2, quit.width, quit.height);
	CP_Settings_Fill(quit.colorFont);
	CP_Font_DrawText(quit.text, quit.x, quit.y);
}
	 
	 
	 void MainMenu_Exit()
{

}

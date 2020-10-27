#include "MainMenu.h"
#include "cprocessing.h"
#include "../Snake/Snake.h"


void MainMenu_Init()
{
	CP_System_SetWindowTitle("Snake");
	CP_Settings_Background(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
	
	//Create play button
	struct Button playbut = 
	{
		.text = "Play",
		.x = WINDOW_WIDTH / 2,
		.y = WINDOW_HEIGHT / 2.25f,
		.width = 200,
		.height = 100,
		.FontC = CP_Color_Create(0, 0, 0, 255),
		.DefaultC = CP_Color_Create(255, 255, 255, 255),
		.HoverC = CP_Color_Create(255, 255, 0, 255),
	};
	play = playbut;

	//create quite button
	struct Button quitbut = 
	{
		.text = "Quit",
		.x = WINDOW_WIDTH / 2,
		.y = WINDOW_HEIGHT * 2 / 3,
		.width = 200,
		.height = 100,
		.FontC = CP_Color_Create(0, 0, 0, 255),
		.DefaultC = CP_Color_Create(255, 255, 255, 255),
		.HoverC = CP_Color_Create(255, 255, 0, 255),
	};
	quit = quitbut;
}

void MainMenu_Update()
{

	CP_Image snakeMenu = CP_Image_Load("./Images/SnakeGame.png");

	//draw "Game Over" image
	float snakeHeight, snakeWidth;
	snakeWidth = WINDOW_WIDTH / 2;
	snakeHeight = (WINDOW_HEIGHT / 5) * 1;
	CP_Image_Draw(snakeMenu, snakeWidth, snakeHeight, 600, 600, 255);

	float mouseX = CP_Input_GetMouseX(), mouseY = CP_Input_GetMouseY();

	
	if ((mouseX >= play.x - play.width / 2) &&
		(mouseX <= play.x + play.width / 2) &&
		(mouseY >= play.y - play.height / 2) &&
		(mouseY <= play.y + play.height / 2))
	{
		CP_Settings_Fill(play.HoverC); //mouse over to the button, colour change
		if (CP_Input_MouseClicked())   //click the play button, direct to snake game
		{
			CP_Engine_SetNextGameState(Snake_init, Snake_update, Snake_exit);
		}
	}
	//draw play button
	CP_Graphics_DrawRect(play.x - play.width / 2, play.y - play.height / 2, play.width, play.height);
	CP_Settings_Fill(play.FontC);
	CP_Font_DrawText(play.text, play.x, play.y);
	CP_Settings_Fill(play.DefaultC);
	
	
	if ((mouseX >= quit.x - quit.width / 2) &&
		(mouseX <= quit.x + quit.width / 2) && 
		(mouseY >= quit.y - quit.height / 2) &&
		(mouseY <= quit.y + quit.height / 2))
	{
		CP_Settings_Fill(quit.HoverC); //mouse over to the button, colour change
		if (CP_Input_MouseClicked()) //click the play button, exit the game
		{
			CP_Engine_Terminate();
		}
	}

	//draw quite button
	CP_Graphics_DrawRect(quit.x - quit.width / 2, quit.y - quit.height / 2, quit.width, quit.height);
	CP_Settings_Fill(quit.FontC);
	CP_Font_DrawText(quit.text, quit.x, quit.y);
	CP_Settings_Fill(quit.DefaultC);
}

void MainMenu_Exit()
{

}
	 
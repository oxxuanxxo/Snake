#include "../header/GameOver.h"
#include "../header/GlobalDef.h"
#include "../Snake/Snake.h"

void GameOver_init()
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	gameOver = CP_Image_Load("../Images/GameOver.png");

	//draw "Game Over" image
	float gameOverWidth, gameOverHeight;
	gameOverWidth = WINDOW_WIDTH / 2;
	gameOverHeight = WINDOW_HEIGHT / 4;
	CP_Image_Draw(gameOver, gameOverWidth, gameOverHeight, 150, 150, 255);

	//draw restart button
	struct myButton restartBut = {
		restartBut.x = WINDOW_WIDTH / 2,
		restartBut.y = (WINDOW_HEIGHT / 5) * 3,
		restartBut.size_x = 100,
		restartBut.size_y = 100,
		restartBut.text = "Restart"
	};

	//draw menu button
	struct myButton menuBut = {
		menuBut.x = WINDOW_WIDTH / 2,
		menuBut.y = (WINDOW_HEIGHT / 5) * 4,
		restartBut.size_x = 100,
		restartBut.size_y = 100,
		restartBut.text = "Menu"
	};

	CP_Graphics_DrawRect(restartBut.x - restartBut.size_x / 2, restartBut.y - restartBut.size_y / 2, restartBut.size_x, restartBut.size_y);
	CP_Settings_Fill(CP_Color_Create(0,0,0,255));
	CP_Font_DrawText(restartBut.text, restartBut.x, restartBut.y);

	CP_Graphics_DrawRect(menuBut.x - menuBut.size_x / 2, menuBut.y - menuBut.size_y / 2, menuBut.size_x, menuBut.size_y);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText(menuBut.text, menuBut.x, menuBut.y);

}
void GameOver_update()
{
	if(CP_Input_MouseClicked())
		if (
			(CP_Input_GetMouseX() >= restartBut.x - restartBut.size_x / 2) && 
			(CP_Input_GetMouseX() <= restartBut.x + restartBut.size_x / 2) &&
			(CP_Input_GetMouseY() >= restartBut.y - restartBut.size_y / 2) &&
			(CP_Input_GetMouseY() >= restartBut.y - restartBut.size_y / 2)
			)
		{
			CP_Engine_SetNextGameState(Snake_init, Snake_update, Snake_exit);
		}
	if(CP_Input_MouseClicked())
		if (
			(CP_Input_GetMouseX() >= menuBut.x - menuBut.size_x / 2) &&
			(CP_Input_GetMouseX() <= menuBut.x + menuBut.size_x / 2) &&
			(CP_Input_GetMouseY() >= menuBut.y - menuBut.size_y / 2) &&
			(CP_Input_GetMouseY() >= menuBut.y - menuBut.size_y / 2)
			)
		{
			CP_Engine_SetNextGameState(MainMenu_Init, MainMenu_Update, MainMenu_Exit);
		}

	
}

void GameOver_render(void)
{
	
}

void GameOver_exit()
{
	
}


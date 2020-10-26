#include "../header/GameOver.h"
#include "../header/GlobalDef.h"
#include "../Snake/Snake.h"
#include "Scenes/HighScoreScene.h"

void GameOver_init(void)
{
	CP_Settings_Background(CP_Color_Create(255, 255, 255, 255));

	//restart button
		restartBut.x = WINDOW_WIDTH * 0.5f;
		restartBut.y = (WINDOW_HEIGHT * 0.1f) * 6.0f;
		restartBut.size_x = 100.0f;
		restartBut.size_y = 100.0f;
		restartBut.text = "Restart";

	//menu button
		menuBut.x = WINDOW_WIDTH * 0.5f;
		menuBut.y = (WINDOW_HEIGHT * 0.1f) * 7.0f;
		menuBut.size_x = 100.0f;
		menuBut.size_y = 100.0f;
		menuBut.text = "Menu";

	//highscore button	
		//@daniel
		highscoreBut.x = WINDOW_WIDTH * 0.5;
		highscoreBut.y = (WINDOW_HEIGHT * 0.1f) * 8.0f;
		highscoreBut.size_x = 100.0f;
		highscoreBut.size_y = 100.0f;
		highscoreBut.text = "Highscore";

	//draw restart button
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Graphics_DrawRect(restartBut.x - restartBut.size_x * 0.5f, restartBut.y - restartBut.size_y * 0.5f, restartBut.size_x, restartBut.size_y);
	CP_Settings_Fill(CP_Color_Create(0,0,0,255));
	CP_Font_DrawText(restartBut.text, restartBut.x, restartBut.y);

	//draw menu button
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Graphics_DrawRect(menuBut.x - menuBut.size_x * 0.5f, menuBut.y - menuBut.size_y *0.5f, menuBut.size_x, menuBut.size_y);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText(menuBut.text, menuBut.x, menuBut.y);

	//draw Highscore button
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Graphics_DrawRect(highscoreBut.x - highscoreBut.size_x * 0.5f, highscoreBut.y - highscoreBut.size_y * 0.5f, highscoreBut.size_x, highscoreBut.size_y);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText(highscoreBut.text, highscoreBut.x, highscoreBut.y);
	

}
void GameOver_update(void)
{
	gameOver = CP_Image_Load("./Images/GameOver.png");

	//draw "Game Over" image
	float gameOverWidth, gameOverHeight;
	gameOverWidth = WINDOW_WIDTH / 2;
	gameOverHeight = (WINDOW_HEIGHT / 5) * 2;
	CP_Image_Draw(gameOver, gameOverWidth, gameOverHeight, 500, 500, 255);

	if(CP_Input_MouseClicked())
		if (
			(CP_Input_GetMouseX() >= restartBut.x - restartBut.size_x * 0.5f) && 
			(CP_Input_GetMouseX() <= restartBut.x + restartBut.size_x * 0.5f) &&
			(CP_Input_GetMouseY() >= restartBut.y - restartBut.size_y * 0.5f) &&
			(CP_Input_GetMouseY() >= restartBut.y - restartBut.size_y * 0.5f)
			)
		{
			CP_Engine_SetNextGameState(Snake_init, Snake_update, Snake_exit);
		}
	if(CP_Input_MouseClicked())
		if (
			(CP_Input_GetMouseX() >= menuBut.x - menuBut.size_x * 0.5f) &&
			(CP_Input_GetMouseX() <= menuBut.x + menuBut.size_x * 0.5f) &&
			(CP_Input_GetMouseY() >= menuBut.y - menuBut.size_y * 0.5f) &&
			(CP_Input_GetMouseY() >= menuBut.y - menuBut.size_y * 0.5f)
			)
		{
			CP_Engine_SetNextGameState(MainMenu_Init, MainMenu_Update, MainMenu_Exit);
		}
		
	if (CP_Input_MouseClicked())
		if (
			(CP_Input_GetMouseX() >= highscoreBut.x - highscoreBut.size_x * 0.5f) &&
			(CP_Input_GetMouseX() <= highscoreBut.x + highscoreBut.size_x * 0.5f) &&
			(CP_Input_GetMouseY() >= highscoreBut.y - highscoreBut.size_y * 0.5f) &&
			(CP_Input_GetMouseY() >= highscoreBut.y - highscoreBut.size_y * 0.5f)
			)
		{
			//@daniel
			CP_Engine_SetNextGameState(HighScore_Init, HighScore_Update, HighScore_Exit);
		}

	
}

void GameOver_render(void)
{
	
}

void GameOver_exit(void)
{
	
}


#include "GameOver.h"
#include "../GlobalDef.h"
#include "../Snake/Snake.h"
#include "HighScoreScene.h"

void GameOver_init(void)
{
	CP_Settings_Background(CP_Color_Create(255, 255, 255, 255));

	//restart button
		restartBut.x = (WINDOW_WIDTH * 0.1f) * 3.0f;
		restartBut.y = WINDOW_HEIGHT * 0.6f;
		restartBut.width = 200.0f;
		restartBut.height = 100.0f;
		restartBut.text = "Restart";
		restartBut.FontC = CP_Color_Create(0, 0, 0, 255);
		restartBut.DefaultC = CP_Color_Create(255, 255, 255, 255);
		restartBut.HoverC = CP_Color_Create(255, 255, 0, 255);

	//menu button
		menuBut.x = (WINDOW_WIDTH * 0.1f) * 5.0f;
		menuBut.y = WINDOW_HEIGHT * 0.6f;
		menuBut.width = 200.0f;
		menuBut.height = 100.0f;
		menuBut.text = "Menu";
		menuBut.FontC = CP_Color_Create(0, 0, 0, 255);
		menuBut.DefaultC = CP_Color_Create(255, 255, 255, 255);
		menuBut.HoverC = CP_Color_Create(255, 255, 0, 255);

	//highscore button	
		//@daniel
		highscoreBut.x = (WINDOW_WIDTH * 0.1f) * 7.0f;
		highscoreBut.y = WINDOW_HEIGHT * 0.6f;
		highscoreBut.width = 200.0f;
		highscoreBut.height = 100.0f;
		highscoreBut.text = "Highscore";
		highscoreBut.FontC = CP_Color_Create(0, 0, 0, 255);
		highscoreBut.DefaultC = CP_Color_Create(255, 255, 255, 255);
		highscoreBut.HoverC = CP_Color_Create(255, 255, 0, 255);

		//quit button
		quitBut.x = WINDOW_WIDTH * 0.5f;
		quitBut.y = WINDOW_HEIGHT * 0.8f;
		quitBut.width = 200.0f;
		quitBut.height = 100.0f;
		quitBut.text = "Quit";
		quitBut.FontC = CP_Color_Create(0, 0, 0, 255);
		quitBut.DefaultC = CP_Color_Create(255, 255, 255, 255);
		quitBut.HoverC = CP_Color_Create(255, 255, 0, 255);

	CP_Settings_TextSize(20);



}
void GameOver_update(void)
{
	gameOver = CP_Image_Load("./Images/GameOver.png");

	//draw "Game Over" image
	float gameOverWidth, gameOverHeight;
	gameOverWidth = WINDOW_WIDTH / 2;
	gameOverHeight = (WINDOW_HEIGHT / 5) * 2;
	CP_Image_Draw(gameOver, gameOverWidth, gameOverHeight, 800, 800, 255);

	if (CP_Input_MouseClicked())
	{
		if (Button_IsHover(&restartBut))
		{
			CP_Engine_SetNextGameState(Snake_init, Snake_update, Snake_exit);
		}
		if (Button_IsHover(&menuBut))
		{
			CP_Engine_SetNextGameState(MainMenu_Init, MainMenu_Update, MainMenu_Exit);
		}
		if (Button_IsHover(&highscoreBut))
		{
			//@daniel
			CP_Engine_SetNextGameState(HighScore_Init, HighScore_Update, HighScore_Exit);
		}
		if (Button_IsHover(&quitBut))
		{
			CP_Engine_Terminate();

		}
	}
		
	GameOver_render();
	
}

void GameOver_render(void)
{
	//draw restart button
	CP_Settings_Fill(restartBut.DefaultC);
	if (Button_IsHover(&restartBut) == true)
	{
		CP_Settings_Fill(restartBut.HoverC);
	}
	CP_Graphics_DrawRect(restartBut.x - restartBut.width * 0.5f, restartBut.y - restartBut.height * 0.5f, restartBut.width, restartBut.height);
	CP_Settings_Fill(restartBut.FontC);
	CP_Font_DrawText(restartBut.text, restartBut.x, restartBut.y);

	//draw menu button
	CP_Settings_Fill(menuBut.DefaultC);
	if (Button_IsHover(&menuBut) == true)
	{
		CP_Settings_Fill(menuBut.HoverC);
	}
	CP_Graphics_DrawRect(menuBut.x - menuBut.width * 0.5f, menuBut.y - menuBut.height * 0.5f, menuBut.width, menuBut.height);
	CP_Settings_Fill(menuBut.FontC);
	CP_Font_DrawText(menuBut.text, menuBut.x, menuBut.y);

	//draw Highscore button
	CP_Settings_Fill(highscoreBut.DefaultC);
	if (Button_IsHover(&highscoreBut) == true)
	{
		CP_Settings_Fill(highscoreBut.HoverC);
	}
	CP_Graphics_DrawRect(highscoreBut.x - highscoreBut.width * 0.5f, highscoreBut.y - highscoreBut.height * 0.5f, highscoreBut.width, highscoreBut.height);
	CP_Settings_Fill(highscoreBut.FontC);
	CP_Font_DrawText(highscoreBut.text, highscoreBut.x, highscoreBut.y);

	//draw Highscore button
	CP_Settings_Fill(quitBut.DefaultC);
	if (Button_IsHover(&quitBut) == true)
	{
		CP_Settings_Fill(quitBut.HoverC);
	}
	CP_Graphics_DrawRect(quitBut.x - quitBut.width * 0.5f, quitBut.y - quitBut.height * 0.5f, quitBut.width, quitBut.height);
	CP_Settings_Fill(quitBut.FontC);
	CP_Font_DrawText(quitBut.text, quitBut.x, quitBut.y);
}

void GameOver_exit(void)
{
	
}


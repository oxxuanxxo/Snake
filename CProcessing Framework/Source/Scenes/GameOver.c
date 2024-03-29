/*!
@file       GameOver.c
@author     Chua Yip Xuan (yipxuan.chua)
@course     GAM100F20
@section	a
@brief      Creates the game over screen after snake body or wall collision. The game over menu have four buttons and a title image:
			1. Restart Button
			2. Main Menu Button
			3. Highscore Button
			4. Quit Button
*//*________________________________________________________________________
_*/

#include "GameOver.h"
#include "../GlobalDef.h"
#include "../Snake/Snake.h"
#include "HighScoreScene.h"

/*!
@brief This function will load the background colour, initialise the button size and position, as well as draw the buttons.
*//*________________________________________________________________________
_*/
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

/*!
@brief This function will update the title image every frame and check if mouse click on the buttons
*//*________________________________________________________________________
_*/
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
			CP_Engine_SetNextGameState(HighScore_Init, HighScore_Update, HighScore_Exit);
		}
		if (Button_IsHover(&quitBut))
		{
			CP_Engine_Terminate();

		}
	}
		
	GameOver_render();
	
}

/*!
@brief This function will render the buttons
*//*________________________________________________________________________
_*/
void GameOver_render(void)
{
	//draw restart button
	RenderButton(&restartBut);

	//draw menu button
	RenderButton(&menuBut);

	//draw Highscore button
	RenderButton(&highscoreBut);

	//draw Highscore button
	RenderButton(&quitBut);

}

void GameOver_exit(void)
{
	
}


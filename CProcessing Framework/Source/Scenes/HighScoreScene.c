/*!
@file HighScoreScene.c
@author Daniel Chua (yeechendaniel.chua)
@date 20/10/20
@brief This file contains the HighScore scene with its init, update render and exit functions
*//*________________________________________________________________________
_*/

#include "HighScoreScene.h"
#include "../../header/GlobalDef.h"
#include <stdio.h>

/*!
@brief initialize values used in high score scene
@param void - none
@return void - none
*//*________________________________________________________________________
_*/
void HighScore_Init(void)
{
	isScorePage = true;
	currScore = score;
	alphabetSelection = 1;

	for (int i = 0; i < 3; ++i)
	{
		name[i] = 'A';
	}
	name[3] = '\0';

	bgColor = CP_Color_Create(255, 255, 255, 255);
	selectionSq = CP_Color_Create(255, 255, 0, 255);
	textColor = CP_Color_Create(0,0, 0, 255);

	windowWidth = CP_System_GetWindowWidth();
	windowHeight = CP_System_GetWindowHeight();

	numScore = LoadScoreFromFile(scoreArr, "./Assets/Highscore.csv");

	hsTextImage = CP_Image_Load("./Images/Highscore.png");

	SortScoreArr(scoreArr, numScore);

}

/*!
@brief Update loop of high score scene, the render is called in here and the isScorePage boolean used to toggle state.
@param void - none
@return void - none
*//*________________________________________________________________________
_*/
void HighScore_Update(void)
{
	float dt = CP_System_GetDt();


	
	if (isScorePage == false)
	{
		debounceTimer += dt;
		if (CP_Input_KeyDown(KEY_UP) && debounceTimer >= 0.2f)
		{
			name[alphabetSelection - 1] += 1;
			debounceTimer = 0.0f;
			if (name[alphabetSelection - 1] > 'Z')
			{
				name[alphabetSelection-1] = 'A';
			}
		}
		else if (CP_Input_KeyDown(KEY_DOWN) && debounceTimer >= 0.2f)
		{
			name[alphabetSelection - 1] -= 1;
			debounceTimer = 0.0f;
			if (name[alphabetSelection - 1] < 'A')
			{
				name[alphabetSelection-1] = 'Z';
			}
		}
		if (CP_Input_KeyDown(KEY_LEFT) && debounceTimer >= 0.2f)
		{
			alphabetSelection -= 1;
			debounceTimer = 0.0f;
			if (alphabetSelection <1)
			{
				alphabetSelection = 3;
			}
		}
		else if (CP_Input_KeyDown(KEY_RIGHT) && debounceTimer >= 0.2f)
		{
			alphabetSelection += 1;
			debounceTimer = 0.0f;
			if (alphabetSelection > 3)
			{
				alphabetSelection = 1;
			}
		}

		if (CP_Input_KeyTriggered(KEY_ENTER))
		{
			if (numScore < 10)
			{
				for (int i = 0; i < 4; ++i)
				{
					scoreArr[numScore].name[i] = name[i];
				}
				scoreArr[numScore].score = currScore;
				SortScoreArr(scoreArr, ++numScore);
				WriteScoreToFile(scoreArr, numScore, "./Assets/Highscore.csv");
			}
			else
			{
				bool newHighscore = false;
				int index = 9;
				while (index >= 0)
				{
					if (scoreArr[index].score < currScore)
					{
						newHighscore = true;
						break;
					}
					index--;
				}
				if (newHighscore)
				{
					for (int i = 0; i < 4; ++i)
					{
						scoreArr[9].name[i] = name[i];
					}
					scoreArr[9].score = currScore;
					SortScoreArr(scoreArr, ++numScore);
					WriteScoreToFile(scoreArr, numScore,"./Assets/Highscore.csv");
				}

			}
			isScorePage = true;
		}

	}
	
	HighScore_Render();
}


/*!
@brief Render loop of high score scene. This function is called at the end of the update loop.
@param void - none
@return void - none
*//*________________________________________________________________________
_*/
void HighScore_Render(void)
{
	CP_Settings_Background(bgColor);

	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);


	CP_Image_Draw(hsTextImage, windowWidth * 0.5f, windowHeight * 0.2f, 500.0f, 500.0f, 255);

	if (isScorePage == false)
	{



		//draw selection square
		CP_Settings_Fill(selectionSq);
		switch (alphabetSelection)
		{
		case 1:
			CP_Graphics_DrawRect(-200.0f +windowWidth * 0.5f, windowHeight * 0.4f - 50.0f, 100.0f, 100.0f);
			break;
		case 2:
			CP_Graphics_DrawRect(0 + windowWidth * 0.5f, windowHeight * 0.4f - 50.0f, 100.0f, 100.0f);
			break;
		case 3:
			CP_Graphics_DrawRect(200.0f + windowWidth * 0.5f, windowHeight * 0.4f - 50.0f, 100.0f, 100.0f);
			break;
		default:
			break;
		}

		//Draw Alphabets

		CP_Settings_TextSize(100.0f);
		CP_Settings_Fill(textColor);

		for (int i = 0; i < 3; ++i)
		{
			sprintf_s(printString, 20,"%c", name[i]);
			CP_Font_DrawText(printString, -150.0f + i * 200.0f + windowWidth * 0.5f , windowHeight * 0.4f);
		}

		sprintf_s(printString, 20, "Score : %d", currScore);
		CP_Font_DrawText(printString, windowWidth * 0.5f, windowHeight * 0.6f);
	}
	
	else
	{

		CP_Settings_Fill(textColor);
		CP_Settings_TextSize(50.0f);
		
		//CP_Font_DrawText("Highscore", windowWidth * 0.35f, windowHeight * 0.1f);
		for (int i = 0; i < numScore; ++i)
		{
			RenderScore(scoreArr[i], windowHeight * (i + 6) * 0.06f);
		}
	}

}


/*!
@brief Exit function for the high score scene. Free memory
@param void - none
@return void - none
*//*________________________________________________________________________
_*/
void HighScore_Exit(void)
{

}
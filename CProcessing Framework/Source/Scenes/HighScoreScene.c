#include "HighScoreScene.h"
#include <stdio.h>

void HighScore_Init(void)
{
	Camera_Init(&cam);
	isScorePage = false;
	currScore = 70;
	alphabetSelection = 1;

	for (int i = 0; i < 3; ++i)
	{
		name[i] = 'A';
	}
	name[3] = '\0';

	bgColor = CP_Color_Create(0, 0, 255, 255);
	selectionSq = CP_Color_Create(255, 255, 255, 255);
	textColor = CP_Color_Create(255,255, 0, 255);

	windowWidth = CP_System_GetWindowWidth();
	windowHeight = CP_System_GetWindowHeight();

	numScore = LoadScoreFromFile(scoreArr, "./Assets/Highscore.csv");
	//SortScoreArr(scoreArr, numScore);

}

void HighScore_Update(void)
{
	dt = CP_System_GetDt();


	
	if (isScorePage == false)
	{
		debounceTimer += dt;
		if (CP_Input_KeyDown(KEY_UP) && debounceTimer >= 0.5f)
		{
			name[alphabetSelection - 1] += 1;
			debounceTimer = 0.0f;
			if (name[alphabetSelection - 1] > 'Z')
			{
				name[alphabetSelection-1] = 'A';
			}
		}
		else if (CP_Input_KeyDown(KEY_DOWN) && debounceTimer >= 0.5f)
		{
			name[alphabetSelection - 1] -= 1;
			debounceTimer = 0.0f;
			if (name[alphabetSelection - 1] < 'A')
			{
				name[alphabetSelection-1] = 'Z';
			}
		}
		if (CP_Input_KeyDown(KEY_LEFT) && debounceTimer >= 0.5f)
		{
			alphabetSelection -= 1;
			debounceTimer = 0.0f;
			if (alphabetSelection <1)
			{
				alphabetSelection = 3;
			}
		}
		else if (CP_Input_KeyDown(KEY_RIGHT) && debounceTimer >= 0.5f)
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
				//SortScoreArr(scoreArr, ++numScore);
				//WriteScoreToFile(scoreArr, numScore, "./Assets/Highscore.csv");
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
					//SortScoreArr(scoreArr, ++numScore);
					//WriteScoreToFile(scoreArr, numScore,"./Assets/Highscore.csv");
				}

			}
			isScorePage = true;
		}

	}
	


	Camera_Update(&cam);

	HighScore_Render();
}

void HighScore_Render(void)
{
	CP_Settings_Background(bgColor);


	CP_Settings_ResetMatrix();

	if (isScorePage == false)
	{
		//draw selection square
		CP_Settings_Fill(selectionSq);
		switch (alphabetSelection)
		{
		case 1:
			CP_Graphics_DrawRect(-300.0f+windowWidth/2.0f, windowHeight/2.0f - 200.0f, 150.0f, 150.0f);
			break;
		case 2:
			CP_Graphics_DrawRect(0 + windowWidth / 2.0f, windowHeight / 2.0f - 200.0f, 150.0f, 150.0f);
			break;
		case 3:
			CP_Graphics_DrawRect(300.0f + windowWidth / 2.0f, windowHeight / 2.0f - 200.0f, 150.0f, 150.0f);
			break;
		default:
			break;
		}

		//Draw Alphabets

		CP_Settings_TextSize(150.0f);
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));

		for (int i = 0; i < 3; ++i)
		{
			sprintf_s(printString, 20,"%c", name[i]);
			CP_Font_DrawText(printString, -275.0f + i * 300.0f + windowWidth / 2.0f, windowHeight / 2.0f -75.0f);
		}
		sprintf_s(printString, 20, "Score : %d", currScore);
		CP_Font_DrawText(printString, windowWidth / 2.0f - 200.0f, windowHeight / 2.0f + 150.0f);
	}
	
	else
	{
		CP_Settings_Fill(textColor);
		CP_Settings_TextSize(75.0f);
		
		CP_Font_DrawText("Highscore", windowWidth * 0.35f, windowHeight * 0.1f);
		for (int i = 0; i < numScore; ++i)
		{
			RenderScore(scoreArr[i], windowHeight * (i + 2) * 0.1f);
		}
	}

}

void HighScore_Exit(void)
{

}
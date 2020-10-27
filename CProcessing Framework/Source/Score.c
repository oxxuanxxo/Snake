/*!
@file Score.c
@author Daniel Chua (yeechendaniel.chua)
@date 20/10/20
@brief This file contains functions that deals with the Score structure type.
*//*________________________________________________________________________
_*/

#include "Score.h"


/*!
@brief Load the score data from an exisiting file (.csv). Assumes size to be 10.
@param score - score pointer, takes in the array and update its values according to the .csv file
@param filePath - c-string that contains the file path to be read.
@return int - returns number of entry read (0-10)
*//*________________________________________________________________________
_*/
int LoadScoreFromFile(struct Score* score, char* filePath)
{
	FILE* file;
	fopen_s(&file, filePath, "r");
	if (file)
	{
		char string[10] = "";
		int index = 0;
		fseek(file, 0, SEEK_SET);
		while (fgets(string,10,file) != NULL)
		{
			if (index >= 10)
			{
				break;
			}
			for (int i = 0; i < 3; ++i)
			{
				score[index].name[i] = string[i];
			}
			score[index].name[3] = '\0';

			score[index].score = atoi(&string[4]);
			++index;
		}
		fclose(file);
		return index;

	}
	
	return 0;
}

/*!
@brief writes the scores based on a score array into a specified (.csv) file.
@param scoreArr - Score pointer that points to the array of scores to be written
@param size - size of score array
@param filePath - c-string that contains the file to be written to.
@return void - none
*//*________________________________________________________________________
_*/
void WriteScoreToFile(struct Score* scoreArr, int size, char* filePath)
{
	FILE* file;
	char buffer[10];
	fopen_s(&file, filePath, "w");

	if (file)
	{
		for (int i = 0; i < size; ++i)
		{
			sprintf_s(buffer, 10, "%s,%d\n", scoreArr[i].name, scoreArr[i].score);
			fprintf_s(file, "%s", buffer);
		}

		
		fclose(file);
	}
}

/*!
@brief Render the score using the CP_Font_DrawText function from CProcessing Framework. This forms one row in the HighScore table.
@param score - the score structure to be rendered
@param y - the height of the text to be rendered,
@return void - none
*//*________________________________________________________________________
_*/
void RenderScore(struct Score score, float y)
{
	CP_Font_DrawText(score.name,CP_System_GetDisplayWidth() * 0.175f ,y);
	char scoreString[6];
	_itoa_s(score.score, scoreString, 6, 10);
	CP_Font_DrawText(scoreString, CP_System_GetDisplayWidth() * 0.3f, y);
}


/*!
@brief Sorts the given score array based on highest to lowest.
@param scoreArr - pointer that points to the Score array to be sorted.
@param size - size of the score array to be sorted.
@return void - none
*//*________________________________________________________________________
_*/
void SortScoreArr(struct Score* scoreArr,int size)
{
	struct Score temp;
	for (int i = size - 1; i >= 1; --i)
	{
		if (scoreArr[i].score > scoreArr[i - 1].score)
		{
			strcpy_s(temp.name, 4, scoreArr[i].name);
			temp.score = scoreArr[i].score;

			strcpy_s(scoreArr[i].name, 4, scoreArr[i - 1].name);
			scoreArr[i].score = scoreArr[i - 1].score;

			strcpy_s(scoreArr[i - 1].name,4,temp.name);
			scoreArr[i - 1].score = temp.score;
		}
	}
}
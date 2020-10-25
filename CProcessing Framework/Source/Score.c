#include "Score.h"

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

void RenderScore(struct Score score, float y)
{
	CP_Font_DrawText(score.name,CP_System_GetDisplayWidth() * 0.125f ,y);
	char scoreString[6];
	_itoa_s(score.score, scoreString, 6, 10);
	CP_Font_DrawText(scoreString, CP_System_GetDisplayWidth() * 0.42f, y);
}

void SortScoreArr(struct Score scoreArr[],int size)
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
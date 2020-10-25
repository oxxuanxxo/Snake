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


void RenderScore(struct Score score, float y)
{
	CP_Font_DrawText(score.name,CP_System_GetDisplayWidth() * 0.125f ,y);
	char scoreString[6];
	_itoa_s(score.score, scoreString, 6, 10);
	CP_Font_DrawText(scoreString, CP_System_GetDisplayWidth() * 0.42f, y);
}

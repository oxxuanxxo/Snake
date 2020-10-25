#ifndef _SCORE_H
#define _SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include "CProcessing.h"

struct Score
{
	char name[4];
	int score;
};

int LoadScoreFromFile(struct Score* ,char* filePath);
void WriteScoreToFile(struct Score* scoreArr,int size ,char* filePath);
void RenderScore(struct Score score, float y);
void SortScoreArr(struct Score scoreArr[], int size);


#endif
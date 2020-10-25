/*!
@file Score.h
@author Daniel Chua (yeechendaniel.chua)
@date 20/10/20
@brief This file define the Score structure type and contains functions that deals with it.
*//*________________________________________________________________________
_*/

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
void SortScoreArr(struct Score* scoreArr, int size);


#endif
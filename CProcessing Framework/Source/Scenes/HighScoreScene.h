/*!
@file HighScoreScene.h
@author Daniel Chua (yeechendaniel.chua)
@date 20/10/20
@brief This file contains the HighScore scene with its init, update render and exit functions
*//*________________________________________________________________________
_*/

#ifndef _HIGH_SCORE_SCENE_H
#define _HIGH_SCORE_SCENE_H

#include "../Camera.h"
#include <stdbool.h>
#include "../Score.h"

//variables to be used in the scene
bool isScorePage;
int windowWidth;
int windowHeight;
int numScore;
int currScore;
int alphabetSelection;
char name[4];
char printString[20];
float debounceTimer;

struct Score scoreArr[10];

CP_Color bgColor;
CP_Color selectionSq;
CP_Color textColor;

CP_Image hsTextImage;

void HighScore_Init(void);
void HighScore_Update(void);
void HighScore_Render(void);
void HighScore_Exit(void);


#endif

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
struct Camera cam;
bool isScorePage;
int currScore;
int alphabetSelection;
char name[4];
char printString[20];
float debounceTimer;
float dt;
int windowWidth;
int windowHeight;
struct Score scoreArr[10];
int numScore;

CP_Color bgColor;
CP_Color selectionSq;
CP_Color textColor;

void HighScore_Init(void);
void HighScore_Update(void);
void HighScore_Render(void);
void HighScore_Exit(void);


#endif
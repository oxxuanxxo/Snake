#ifndef _HIGH_SCORE_SCENE_H
#define _HIGH_SCORE_SCENE_H

#include "../Camera.h"
#include <stdbool.h>
#include "../Score.h"


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

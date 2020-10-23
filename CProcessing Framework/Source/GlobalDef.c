#include "../header/GlobalDef.h"
#include "stdio.h"
void UpdateScore(int increment)
{
	score += increment;
	sprintf_s(scoreText, 15, "Score : %d", score);
	return;
}
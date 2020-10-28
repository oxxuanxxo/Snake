#include "GlobalDef.h"
#include <stdio.h>//for sprintf

/*!
@file GlobalDef.c
@author Leong Jun Xiang(junxiang.leong)
@date 23/10/2020
@brief contains update score function
*//*_________________________________________________________________________*/

/*!
@brief update the score variable in globaldef.h by the value provided
@param increement: the value to increase score by
*//*_________________________________________________________________________*/
void UpdateScore(int increment)
{
	score += increment;
	sprintf_s(scoreText, 15, "Score : %d", score);
	return;
}
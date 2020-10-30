/* !
@file       WallCollision.h
@author     Wu Pei Fang(peifang.w)
@brief      header file of WallCollision.c
*//*__________________________________________________________________________*/

#ifndef WALLCOLLISION_H
#define WALLCOLLISION_H
#define WALL 1
#define grid_WIDTH 24
#define grid_HEIGHT 16

#include "cprocessing.h"
#include "../Snake/SnakeBody.h"

int x, y;
int grid[grid_WIDTH][grid_HEIGHT];


void WallCollision_Init(void);
void WallCollision_Update(struct SnakeBody* sb);
void WallCollision_Exit(void);


#endif
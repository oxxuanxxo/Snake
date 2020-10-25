#pragma once
#ifndef WALLCOLLISION_H
#define WALLCOLLISION_H
#define WALL 1
#define grid_WIDTH 60
#define grid_HEIGHT 40
#include "cprocessing.h"
#include "Snake/SnakeBody.h"

int x, y;
int grid[grid_WIDTH][grid_HEIGHT];


void WallCollision_Init(void);
void WallCollision_Update(struct SnakeBody* sb);
void WallCollision_Exit(void);


#endif
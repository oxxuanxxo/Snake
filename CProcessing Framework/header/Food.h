#ifndef FOOD_H
#define FOOD_H

#include "../CProcessing/inc/cprocessing.h"
#include "../Snake/SnakeBody.h"

int foodCollide;
CP_Vector foodPos;
CP_Image foodImg;

void FoodCollision_init();
void foodSpawn(struct SnakeBody* sb);
void FoodCollision_update(struct SnakeBody* sb);
void FoodCollision_render(void);



#endif
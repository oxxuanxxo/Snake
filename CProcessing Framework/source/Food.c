#include "../header/Food.h"
#include "../Snake/SnakeBody.h"


void FoodCollision_init()
{
	//set initial coordinates for food
	foodPos = CP_Vector_Set(100.0f, 100.0f);
}
void FoodCollision_update(struct SnakeBody* sb)
{

	/*
		//Check if head of snake collided with the apple (snakehead.x, snakehead.y touches food.x and food.y)
				if (sb.position.x == food_Y && sb.position.y == food_X)
					{	
						sb lenghth ++;
					}
				//food trail should disappear after collision which also means food spawn location immediately after eaten
				//food should also not land on the snake or wall 
				do
				{	
					//spawn a new location
					food.x = randnum(0,0);
					food.y = randnum(0,0);
				}
				while((food.x == sb.length.x || food.y == sb.length.y) && (food.x == coordsofwalls[i].x || food.y == coordofwalls.y[i]))
	*/
	CP_Vector food_Dist = CP_Vector_Subtract(foodPos, sb-> head -> position);
	CP_Vector food_Norm = CP_Vector_Normalize(food_Dist);
		if ((food_Norm.x == sb->dir.x) && (food_Norm.y == sb->dir.y)) 
		{
			SnakeBodyAddNode(sb);
			foodCollide = 1;
		}
		
		if (foodCollide == 1)
		{
			foodPos.x = (float)((int)CP_Random_GetFloat() %24 - 12)*(sb -> bodyWidth); 
			//1200/50 = 24;  %24 is to get grid coords; 
			foodPos.y = (float)((int)CP_Random_GetFloat() % 800);

		}
		

	}
	

void FoodCollision_render(void)
{
	
	
}


void FoodCollision_exit()
{

}
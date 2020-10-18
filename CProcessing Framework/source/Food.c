#include "../CProcessing/inc/cprocessing.h"
#include "../header/Food.h"
#include "../Snake/SnakeBody.h"


void FoodCollision_init()
{
	//set initial coordinates for food
	food_Y = 100.0f;  
	food_X = 100.0f;
	CP_Settings_Fill(CP_Color_Create(0, 255, 0, 0));
	CP_Graphics_DrawRect(food_Y, food_X, 50, 50);
}
void FoodCollision_update()
{
	/*
		//Check if head of snake collided with the apple (snakehead.x, snakehead.y touches food.x and food.y)
				if (sn.position.x == food_Y && sn.position.y == food_X)
					{	
						sb lenghth ++;
					}
		//food trail should disappear after collision
				
	*/
	
	
}

/*void FoodCollision_render(void)
{
	
}
*/

void FoodCollision_exit()
{

}
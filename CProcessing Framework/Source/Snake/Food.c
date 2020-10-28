/*!
@file       Food.c
@author     Chua Yip Xuan (yipxuan.chua)
@course     GAM100F20
@section	a
@brief      This function will check for food collision, and spawn the food at random location
*//*________________________________________________________________________
_*/

#include "Food.h"
#include "SnakeBody.h"
#include "../GlobalDef.h"

/*!
@brief This function loads the food position as well as the image of the food
*//*________________________________________________________________________
_*/
void FoodCollision_init(void)
{
	//set initial coordinates for food
	foodPos = CP_Vector_Set(100.0f, 100.0f);
	foodImg = CP_Image_Load("Images/Apple.png");
}

/*!
@brief This function will spawn food at random positions when called
*//*________________________________________________________________________
_*/
void foodSpawn(struct SnakeBody* sb)
{
	int ScreenWidth, ScreenHeight;
	ScreenWidth = (int)(WINDOW_WIDTH-100) / (int)(sb->bodyWidth); 
	ScreenHeight = (int)(WINDOW_HEIGHT-100)/ (int)(sb->bodyHeight); 
		
	foodPos.x = (float)((int)((CP_Random_GetInt() % ScreenWidth) - (ScreenWidth / 2))) * (sb->bodyWidth);
	foodPos.y = (float)((int)((CP_Random_GetInt() % ScreenHeight) - (ScreenHeight / 2))) * (sb->bodyHeight);
	
}


/*!
@brief This function will check for food collision every frame using CP_Vector_Distance, snakebody node will increase after food collision
		After food collision, food spawn function will be called to spawn the food at random location (also to make sure the food does not spawn
		on the snakebody and wall)
*//*________________________________________________________________________
_*/
void FoodCollision_update(struct SnakeBody* sb)
{

	if ((foodPos.x == sb->head->position.x) && (foodPos.y == sb->head->position.y))
	{
		float a = CP_Vector_Distance(foodPos, sb->head->position);
		if (a <= 50)
		{
			foodCollide = 1;
			UpdateScore(1);
			SnakeBodyAddNode(sb);
		}
	}
		while (foodCollide)
		{
			foodSpawn(sb);
			unsigned int i;
			for (i = 0; i < (sb->length); ++i)
			{
				if (CP_Vector_Distance(foodPos, sb->list[i].position) < 10)
				{
					break;
				}
			}
			if (i == sb->length)
			{
				foodCollide = 0;
				return;
			}
		}
}

/*!
@brief This function will render the food image onto the food position coordinates at grid size
*//*________________________________________________________________________
_*/
void FoodCollision_render(void)
{
	CP_Image_Draw(foodImg, foodPos.x + 25.0f, foodPos.y + 25.0f, 50.0f, 50.0f, 255);
}


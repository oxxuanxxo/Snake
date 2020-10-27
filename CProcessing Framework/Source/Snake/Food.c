#include "Food.h"
#include "SnakeBody.h"
#include "../GlobalDef.h"


void FoodCollision_init(void)
{
	//set initial coordinates for food
	foodPos = CP_Vector_Set(100.0f, 100.0f);
	foodImg = CP_Image_Load("Images/Apple.png");
}

void foodSpawn(struct SnakeBody* sb)
{
	int ScreenWidth, ScreenHeight;
	ScreenWidth = (int)(WINDOW_WIDTH-100) / (int)(sb->bodyWidth); //1200 / 50 = 24
	ScreenHeight = (int)(WINDOW_HEIGHT-100)/ (int)(sb->bodyHeight); //800 / 50 = 16
		
	foodPos.x = (float)((int)((CP_Random_GetInt() % ScreenWidth) - (ScreenWidth / 2))) * (sb->bodyWidth);
	foodPos.y = (float)((int)((CP_Random_GetInt() % ScreenHeight) - (ScreenHeight / 2))) * (sb->bodyHeight);
	
	//foodPos.x = (float)((int)CP_Random_GetFloat() %24 - 12)*(sb -> bodyWidth); 
	//1200/50 = 24;  %24 is to get grid coords; -12 is to get pos and neg
	
}

void FoodCollision_update(struct SnakeBody* sb)
{
	//CP_Vector food_Dist = CP_Vector_Subtract(foodPos, sb->head->position);
	//CP_Vector food_Norm = CP_Vector_Normalize(food_Dist);

	if ((foodPos.x == sb->head->position.x) && (foodPos.y == sb->head->position.y))
	{
		float a = CP_Vector_Distance(foodPos, sb->head->position);
		if (a <= 50)
		{
			//@daniel
			foodCollide = 1;
			UpdateScore(1);
			SnakeBodyAddNode(sb);
		}
	}

		// @todo make sure it spawn on empty space, not on snake and wall
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

void FoodCollision_render(void)
{
	CP_Image_Draw(foodImg, foodPos.x + 25.0f, foodPos.y + 25.0f, 50.0f, 50.0f, 255);
}


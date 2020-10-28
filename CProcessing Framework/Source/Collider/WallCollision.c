#include "cprocessing.h"
#include "WallCollision.h"
#include "../Scenes/GameOver.h"
#include "../Snake/SnakeBody.h"
#include "../GlobalDef.h"


void WallCollision_Init(void)
{
	for (x = 0; x < grid_WIDTH; x++) //create wall top and bottom
	{
		grid[x][0] = WALL;
		grid[x][grid_HEIGHT - 1] = WALL;
	}

	for (y = 0; y < grid_HEIGHT; y++) //create wall left and right
	{
		grid[0][y] = WALL;
		grid[grid_WIDTH - 1][y] = WALL;
	}

}


void WallCollision_Update(struct SnakeBody* sb)
{

	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255)); //fill the wall white color
	for (x = 0; x < grid_WIDTH; x++) //Draw the wall
	{
		for (y = 0; y < grid_HEIGHT; y++)
		{
			if (grid[x][y] == WALL)
			{
				CP_Graphics_DrawRect((float)x * 50, (float)y * 50, (float)50, (float)50);
			}
		}
	}

	//calculate the position snake will collide and die
	float calone = WINDOW_WIDTH / 2 - 50;
	float caltwo = WINDOW_HEIGHT / 2 - 50;

	if (sb->head->position.x >= calone || sb->head->position.x < -calone ||
		sb->head->position.y >= caltwo || sb->head->position.y < -caltwo) //snake head collide with wall, proceed to game over page
	{
		CP_Engine_SetNextGameState(GameOver_init, GameOver_update, GameOver_exit);
	}
}

void WallCollision_Exit(void)
{

}

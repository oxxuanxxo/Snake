#include "cprocessing.h"
#include "WallCollision.h"
#include "../header/GameOver.h"
#include "../Snake/SnakeBody.h"
#include "../header/GlobalDef.h"



void WallCollision_Init(void)
{

	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));

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


void WallCollision_Update(void)
{
	for (x = 0; x < grid_WIDTH; x++)
	{
		for (y = 0; y < grid_HEIGHT; y++)
		{
			if (grid[sb->head][sb->head] == WALL)
			{
				CP_Graphics_DrawRect((float)x * 20, (float)y * 20, (float)20, (float)20);
				CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
			}
		}
	}

	if (grid[sb->head][sb->head]==WALL)
	{
		CP_Engine_SetNextGameState(GameOver_init, GameOver_update, GameOver_exit);
	}
}

void WallCollision_Exit()
{

}

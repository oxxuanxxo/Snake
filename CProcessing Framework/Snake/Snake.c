#include "Snake.h"
#include "../Source/Scenes/DemoScene.h"
#include "../header/Food.h"
#include "../header/GameOver.h"
#include "../WallCollision.h"


void Snake_init()
{
	Camera_Init(&cam);
	bg = CP_Color_Create(0, 0, 0, 255);

	score = 0;

	WallCollision_Init();
	snakeBody = CreateSnakeBody(0.f,0.f,50.f,50.f,0.20f);
	SnakeBodyAddNode(&snakeBody);
	SnakeBodyAddNode(&snakeBody);
	SnakeBodyAddNode(&snakeBody);
	SnakeBodyAddNode(&snakeBody);
	SnakeBodyAddNode(&snakeBody);
	
	FoodCollision_init();
}
void Snake_update()
{
	float dt = CP_System_GetDt();
	Snake_gameupdate(dt);
	Snake_inputs(dt);

	//draw text
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText(scoreText, 100.f, 100.f);
	//camera update
	Camera_Update(&cam);
	Snake_render();
	
}
void Snake_gameupdate(float dt)
{
	SnakeBodyUpdate(&snakeBody,dt);
	if (SnakeBodyCollision(&snakeBody))
	{
		CP_Engine_SetNextGameState(GameOver_init, GameOver_update, GameOver_exit);
		//CP_Engine_SetNextGameState(DemoScene_Init, DemoScene_Update, DemoScene_Exit);
		//GameOver_init();
		//GameOver_update();
	}
	FoodCollision_update(&snakeBody);
	WallCollision_Update(&snakeBody);
}
void Snake_inputs(float dt)
{
	if (CP_Input_KeyDown(KEY_ESCAPE))//press esc to terminate app
	{
		CP_Engine_Terminate();
	}

	if (CP_Input_KeyDown(KEY_W) )
	{
		SnakeSetDirection(&snakeBody, CP_Vector_Set(0.f, 1.f));
	}
	else if (CP_Input_KeyDown(KEY_S))
	{
		SnakeSetDirection(&snakeBody, CP_Vector_Set(0.f, -1.f));
	}
	if (CP_Input_KeyDown(KEY_A))
	{
		SnakeSetDirection(&snakeBody, CP_Vector_Set(-1.f, 0.f));
	}
	else if (CP_Input_KeyDown(KEY_D))
	{
		SnakeSetDirection(&snakeBody, CP_Vector_Set(1.f, 0.f));
	}
}
void Snake_render(void)
{
	CP_Settings_Background(bg);//set bg to black and works as a clear buffer
	SnakeBodyRender(&snakeBody);
	FoodCollision_render();
}


void Snake_exit()
{
	DeleteSnakeBody(&snakeBody);
}
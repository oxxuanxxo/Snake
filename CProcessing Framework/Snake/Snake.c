#include "Snake.h"
#include "../Source/Scenes/DemoScene.h"
#include "../header/Food.h"


void Snake_init()
{
	Camera_Init(&cam);
	bg = CP_Color_Create(0, 0, 0, 255);
	snakeBody = CreateSnakeBody(0.f,0.f,50.f,50.f,0.25f);
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
	//camera update
	Camera_Update(&cam);
	Snake_render();

}
void Snake_gameupdate(float dt)
{
	SnakeBodyUpdate(&snakeBody,dt);
	if (SnakeBodyCollision(&snakeBody))
	{
		CP_Engine_SetNextGameState(DemoScene_Init, DemoScene_Update, DemoScene_Exit);
	}
	FoodCollision_update(&snakeBody);
}
void Snake_inputs(float dt)
{
	if (CP_Input_KeyDown(KEY_ESCAPE))//press esc to terminate app
	{
		CP_Engine_Terminate();
	}
	if (CP_Input_KeyTriggered(KEY_E))
	{
		SnakeBodyAddNode(&snakeBody);
	}

	if (CP_Input_KeyDown(KEY_W))
	{
		snakeBody.dir = CP_Vector_Set(0.f, 1.f);
	}
	else if (CP_Input_KeyDown(KEY_S))
	{
		snakeBody.dir = CP_Vector_Set(0.f, -1.f);
	}
	if (CP_Input_KeyDown(KEY_A))
	{
		snakeBody.dir = CP_Vector_Set(-1.f, 0.f);
	}
	else if (CP_Input_KeyDown(KEY_D))
	{
		snakeBody.dir = CP_Vector_Set(1.f, 0.f);
	}
}
void Snake_render(void)
{
	CP_Settings_Background(bg);//set bg to black and works as a clear buffer
	CP_Graphics_DrawRect(100.0f, 100.0f, 50.0f, 50.0f);
	SnakeBodyRender(&snakeBody);
	FoodCollision_render();
}


void Snake_exit()
{
	DeleteSnakeBody(&snakeBody);
}
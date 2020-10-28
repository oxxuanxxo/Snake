#include "Snake.h"
#include "../Scenes/DemoScene.h"
#include "Food.h"
#include "../Scenes/GameOver.h"
#include "../Collider/WallCollision.h"

/*!
@file Snake.c
@brief the game scene
*//*_________________________________________________________________________*/

/*!
@brief the initialization phase for all the elements of the game
*//*_________________________________________________________________________*/
void Snake_init(void)
{
	Camera_Init(&cam);
	bg = CP_Color_Create(0, 0, 0, 255);

	score = 0;
	scoreText[0] = '\0';

	WallCollision_Init();
	snakeBody = CreateSnakeBody(0.f,0.f,50.f,50.f,0.20f); // create the initial head
	//the block of the body
	SnakeBodyAddNode(&snakeBody);
	SnakeBodyAddNode(&snakeBody);
	SnakeBodyAddNode(&snakeBody);
	SnakeBodyAddNode(&snakeBody);
	SnakeBodyAddNode(&snakeBody);
	
	FoodCollision_init();
}
/*!
@brief contains all the calculations and rendering sequence of the game
*//*_________________________________________________________________________*/
void Snake_update(void)
{
	float dt = CP_System_GetDt();// get deltatime

	Snake_gameupdate(dt);
	Snake_inputs();

	//draw text
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText(scoreText, 100.f, 100.f);
	//camera update
	Camera_Update(&cam);
	Snake_render();
	
}
/*!
@brief updates for the snake game object and interactions 
	   closely related to it
@param dt deltatime for counting time elpased
*//*_________________________________________________________________________*/
void Snake_gameupdate(float dt)
{
	SnakeBodyUpdate(&snakeBody,dt);
	if (SnakeBodyCollision(&snakeBody))
	{
		CP_Engine_SetNextGameState(GameOver_init, GameOver_update, GameOver_exit);
	}
	FoodCollision_update(&snakeBody);
	WallCollision_Update(&snakeBody);
}
/*!
@brief handles all the inputs for the snake game
*//*_________________________________________________________________________*/
void Snake_inputs()
{
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
/*!
@brief contains all rendering functions for the snake game 
		after the camera update
*//*_________________________________________________________________________*/
void Snake_render(void)
{
	CP_Settings_Background(bg);//set bg to black and works as a clear buffer
	SnakeBodyRender(&snakeBody);
	FoodCollision_render();
}

/*!
@brief exit sequence for clearing any memory in the game
*//*_________________________________________________________________________*/
void Snake_exit(void)
{
	DeleteSnakeBody(&snakeBody);//freeing up memory allocated for the snake body
}
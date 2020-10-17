#include "DemoScene.h"

void DemoScene_Init(void)
{
	Camera_Init(&cam);
	bgColor = CP_Color_Create(0, 0, 255, 255);
	cubeColor = CP_Color_Create(255, 0, 0, 255);
	cubePos = CP_Vector_Set(0, 0);
	playerSpeed = 100.0f;
}

void DemoScene_Update(void)
{
	float dt = CP_System_GetDt();
	
	//ur game logic here
	if (CP_Input_KeyDown(KEY_W))
	{
		cubePos.y += playerSpeed * dt;
		//playerSpeed += 10.0f;
	}
	else if (CP_Input_KeyDown(KEY_S))
	{
		cubePos.y -= playerSpeed * dt;
		//playerSpeed += 10.0f;
	}


	else if (CP_Input_KeyDown(KEY_A))
	{
		cubePos.x -= playerSpeed * dt;
		//playerSpeed += 10.0f;
	}
	else if (CP_Input_KeyDown(KEY_D))
	{
		cubePos.x += playerSpeed * dt;
		//playerSpeed += 10.0f;
	}

	

	//camera update
	Camera_Update(&cam);

	//Render
	DemoScene_Render();
}

void DemoScene_Render(void)
{
	CP_Settings_Background(bgColor);

	CP_Graphics_DrawRect(cubePos.x, cubePos.y, 50.0f, 50.0f);
}

void DemoScene_Exit(void)
{
}
#include "TestScene.h"
#include "../Snake/Snake.h"
#include <stdio.h>

void TestScene_Init(void)
{
	Camera_Init(&cam);
	bg = CP_Color_Create(0, 0, 255, 255);
	rect = CP_Color_Create(255, 255, 255, 255);

	appleImage = CP_Image_Load("./Images/Apple.png");
	playerPos = CP_Vector_Set(0, 0);
}

void TestScene_Update(void)
{

	float dt = CP_System_GetDt();
	float playerSpeed = 50.0f;

	CP_Settings_Background(bg);
	
	if (CP_Input_KeyDown(KEY_W))
	{
		playerPos.y += playerSpeed * dt;
	}
	if (CP_Input_KeyDown(KEY_S))
	{
		playerPos.y -= playerSpeed * dt;
	}
	if (CP_Input_KeyDown(KEY_D))
	{
		playerPos.x += playerSpeed * dt;
	}
	if (CP_Input_KeyDown(KEY_A))
	{
		playerPos.x -= playerSpeed * dt;
	}

	if (CP_Input_KeyDown(KEY_L))
	{
		CP_Engine_SetNextGameState(Snake_init, Snake_update, Snake_exit);
	}


	Camera_Input(&cam);

	Camera_Update(&cam);

	TestScene_Render();


}

void TestScene_Render(void)
{
	CP_Settings_Fill(rect);
	for (int i = 0; i < 50; ++i)
	{
		CP_Graphics_DrawRect((float)i * 10.0f, -5.0f, 10.0f, 10.0f);
	}

	CP_Image_Draw(appleImage, playerPos.x, playerPos.y, 10.0f, -10.0f, 255);


	//Render UI
	CP_Settings_ResetMatrix();

	CP_Settings_TextSize(25.0f);
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));

	char string[50];

	CP_Vector worldCoord = Camera_ScreenToWorldSpace(&cam,CP_Vector_Set( CP_Input_GetMouseX(), CP_Input_GetMouseY()) );
	sprintf_s(string, 50 ,"%.2f,%.2f", worldCoord.x, worldCoord.y);
	CP_Font_DrawText(string, CP_Input_GetMouseX(), CP_Input_GetMouseY() );


	//CP_Vector screenCoods = Camera_WorldToScreenSpace(&cam, playerPos);

	//sprintf_s(string, 50, "%.2f , %.2f", screenCoods.x, screenCoods.y);
	//CP_Font_DrawText(string, screenCoods.x, screenCoods.y - 10);
}

void TestScene_Exit(void)
{

}

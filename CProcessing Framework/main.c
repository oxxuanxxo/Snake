//---------------------------------------------------------
// file:	main.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	Main entry point for the sample project
//			of the CProcessing library
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright � 2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#define WINDOW_WIDTH 1240
#define WINDOW_HEIGHT 800
#include "cprocessing.h"
#include "Snake/Snake.h"
#include "Source/Scenes/TestScene.h"
// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void game_init(void)
{
	// initialize variables and CProcessing settings for this gamestate
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void game_update(void)
{
	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void game_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}

// main() the starting point for the program
// CP_Engine_SetNextGameState() tells CProcessing which functions to use for init, update and exit
// CP_Engine_Run() is the core function that starts the simulation
int main(void)
{
	CP_System_SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	//CP_Engine_SetNextGameState(TestScene_Init,TestScene_Update,TestScene_Exit);
	CP_Engine_SetNextGameState(Snake_init, Snake_update, Snake_exit);
	//CP_Engine_SetNextGameState(DemoScene_Init, DemoScene_Update, DemoScene_Exit);
	CP_Engine_Run();
	return 0;
}

#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include <cprocessing.h>


struct Button
{
	const char* text;
	float x, y, width, height;
	CP_Color FontC, DefaultC, HoverC;
};
struct Button play;
struct Button quit;


void MainMenu_Init(void);
void MainMenu_Update(void);
void MainMenu_Exit(void);

#endif
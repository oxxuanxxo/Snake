#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include <cprocessing.h>

struct Button
{
	const char* text;
	float x, y;
	float width, height;
	CP_Color colorFont;
	CP_Color colorDefault;
	CP_Color colorHover;
	void(*onClick)(void);
};
struct Button play;
struct Button quit;
CP_Color colorDefault;
CP_Color colorHover;

void Play_OnClick(void);
void MainMenu_Init(void);
void MainMenu_Update(void);
void MainMenu_Exit(void);

#endif
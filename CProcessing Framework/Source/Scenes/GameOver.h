#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "cprocessing.h"
#include "MainMenu.h"

CP_Image gameOver;

void GameOver_init(void);
void GameOver_update(void);
void GameOver_render(void);
void GameOver_exit(void);

struct myButton
{
	float x, y, size_x, size_y;
	char* text;
};

struct myButton restartBut;
struct myButton menuBut;
struct myButton highscoreBut;
struct myButton quitBut;


#endif 
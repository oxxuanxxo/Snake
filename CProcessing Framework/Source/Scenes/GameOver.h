#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "cprocessing.h"
#include "MainMenu.h"
#include "../Button.h"

CP_Image gameOver;

void GameOver_init(void);
void GameOver_update(void);
void GameOver_render(void);
void GameOver_exit(void);


struct Button restartBut;
struct Button menuBut;
struct Button highscoreBut;
struct Button quitBut;


#endif 
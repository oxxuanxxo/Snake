/*!
@file       GameOver.h
@author     Chua Yip Xuan (yipxuan.chua)
@course     GAM100F20
@section	a
@brief      This header file stores all important variables need for GameOver.c
*//*________________________________________________________________________
_*/

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
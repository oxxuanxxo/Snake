/* !
@file       MainMenu.h
@author     Wu Pei Fang(peifang.w)
@brief      Header file of MainMenu.c
*//*__________________________________________________________________________*/
#ifndef MAINMENU_H
#define MAINMENU_H

#include "cprocessing.h"
#include "../Button.h"


struct Button play;
struct Button quit;


void MainMenu_Init(void);
void MainMenu_Update(void);
void MainMenu_Exit(void);

#endif
#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#include <cprocessing.h>
#include "Source/Button.h"


struct Button play;
struct Button quit;


void MainMenu_Init(void);
void MainMenu_Update(void);
void MainMenu_Exit(void);

#endif
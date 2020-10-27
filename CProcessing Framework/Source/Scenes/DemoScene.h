#ifndef _DEMO_SCENE_H
#define _DEMO_SCENE_H

#include "../Camera/Camera.h"

struct Camera cam;

CP_Color bgColor;
CP_Color cubeColor;

CP_Vector cubePos;
float playerSpeed;

void DemoScene_Init(void);
void DemoScene_Update(void);
void DemoScene_Render(void);
void DemoScene_Exit(void);


#endif


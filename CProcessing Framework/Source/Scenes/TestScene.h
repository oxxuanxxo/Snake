#ifndef _TEST_SCENE_H
#define _TEST_SCENE_H

#include "../Camera.h"

struct Camera cam;

CP_Color bg;
CP_Color rect;
CP_Color playerRect;

CP_Vector playerPos;

CP_Image appleImage;


void TestScene_Init(void);
void TestScene_Update(void);
void TestScene_Exit(void);


#endif
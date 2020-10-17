#ifndef SNAKE_H
#define SNAKE_H
#include "../CProcessing/inc/cprocessing.h"
#include "../Source/Camera.h"
#include "SnakeBody.h"


CP_Color bg;
struct Camera cam;

//snake
struct SnakeBody snakeBody;

void Snake_init(void);
void Snake_update(void);
void Snake_exit(void);

//other functions
void Snake_render(void);
void Snake_inputs(float dt);
void Snake_gameupdate(float dt);


#endif // !SNAKE_H

#ifndef SNAKE_H
#define SNAKE_H
#include "cprocessing.h"
#include "../Camera/Camera.h"
#include "SnakeBody.h"
#include "../Scenes/GameOver.h"


CP_Color bg; //background color
struct Camera cam;

//snake
struct SnakeBody snakeBody;

void Snake_init(void);
void Snake_update(void);
void Snake_exit(void);

//other functions
void Snake_render(void);
void Snake_inputs();
void Snake_gameupdate(float dt);


#endif // !SNAKE_H

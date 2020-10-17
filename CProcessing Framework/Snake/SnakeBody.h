#pragma once
#ifndef SNAKEBODY_H
#define SNAKEBODY_H
#define DEFAULTSNAKELENGTH 4
#include "../CProcessing/inc/cprocessing.h"


struct SnakeNode
{
	CP_Vector position;
	//can add other variables for rendering different parts for the body
};

struct SnakeBody
{
	unsigned int listSize;
	unsigned int length;

	float bodyWidth;
	float bodyHeight;
	float speed;
	float updateTime;
	float timer;
	CP_Vector dir;

	struct SnakeNode* head;//head of the snake
	struct SnakeNode* last;//most recently created node

	struct SnakeNode* list;
};
//width and height per node of the body(prefable to be same size)
struct SnakeBody CreateSnakeBody(float x, float y, float width, float height, float tickTime);
void DeleteSnakeBody(struct SnakeBody* sb);

void SnakeBodyAddNode(struct SnakeBody* sb);
void SnakeBodyResizeList(struct SnakeBody* sb);

void SnakeBodyRender(struct SnakeBody* sb);
void SnakeBodyUpdate(struct SnakeBody* sb, float dt);

#endif // !SNAKEBODY_H

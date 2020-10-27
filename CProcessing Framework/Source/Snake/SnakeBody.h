#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "cprocessing.h"
#include "../Collider/BoxCollider.h"
#include "../GlobalDef.h"

//snake head


struct SnakeNode
{
	CP_Vector position;
	struct BoxCollider bc;
	//can add other variables for rendering different parts for the body
};

struct SnakeBody
{
	int immunity;

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

struct SnakeNode CreateSnakeNode(float x, float y, float width, float height);
struct SnakeBody CreateSnakeBody(float x, float y, float width, float height, float tickTime);
void DeleteSnakeBody(struct SnakeBody* sb);

void SnakeBodyAddNode(struct SnakeBody* sb);
void SnakeBodyResizeList(struct SnakeBody* sb);

void SnakeBodyRender(struct SnakeBody* sb);
void SnakeBodyUpdate(struct SnakeBody* sb, float dt);

//handles collision for the whole body
int SnakeBodyCollision(struct SnakeBody* sb);
void SnakeSetDirection(struct SnakeBody* sb,CP_Vector direction);

#endif // !SNAKEBODY_H

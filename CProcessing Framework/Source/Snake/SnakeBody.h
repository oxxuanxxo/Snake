#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "cprocessing.h"
#include "../Collider/BoxCollider.h"
#include "../GlobalDef.h"

//body nodes of the snake
struct SnakeNode
{
	CP_Vector position;
	struct BoxCollider bc;
	//can add other variables for rendering different parts for the body
};
//container for the body nodes
struct SnakeBody
{
	int immunity;//immunity time when just spawns

	unsigned int listSize; //size of the SnakeNode list
	unsigned int length;//amount of variables in SnakeNode list

	float bodyWidth;//width of the snakenode
	float bodyHeight;//height of the snakenode

	float speed;//how fast the snake moves per tick
	float updateTime; //update time for moving
	float timer;

	CP_Vector dir; // direction the snake is facing

	struct SnakeNode* head;//head of the snake
	struct SnakeNode* last;//most recently created node

	struct SnakeNode* list;//contains all the nodes of the snake
};
//width and height per node of the body(prefable to be same size)

struct SnakeNode CreateSnakeNode(float x, float y, float width, float height);
struct SnakeBody CreateSnakeBody(float x, float y, float width, float height, float tickTime);

//freeing up memory 
void DeleteSnakeBody(struct SnakeBody* sb);
//adding a snakenode
void SnakeBodyAddNode(struct SnakeBody* sb);
//resize the list when the old list is too big
void SnakeBodyResizeList(struct SnakeBody* sb);

//drawing of the snake
void SnakeBodyRender(struct SnakeBody* sb);
//updates for movement
void SnakeBodyUpdate(struct SnakeBody* sb, float dt);

//handles collision for the whole body
int SnakeBodyCollision(struct SnakeBody* sb);
//checks if the direction set is possible
void SnakeSetDirection(struct SnakeBody* sb,CP_Vector direction);

#endif // !SNAKEBODY_H

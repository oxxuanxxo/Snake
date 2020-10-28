#include "SnakeBody.h"
#include <stdlib.h>
#include <stdio.h>
/*!
@file SnakeBody.c
@author	Leong Jun Xiang(junxiang.leong)
@date 21/10/2020
@brief contains function for creating, rendering and moving the snake
*//*_________________________________________________________________________*/

/*!
@brief create a SnakeNode with the predefined variables
@param x: position on the x coordinate
@param y: position on the y coordinate
@param width: Width of the Node
@param height: height of the Node
@return SnakeNode: returns a snakenode that has been 
					created and a collider done
*//*_________________________________________________________________________*/
struct SnakeNode CreateSnakeNode(float x, float y, float width, float height)
{
	struct SnakeNode sn;
	sn.position.x = x;
	sn.position.y = y;
	//bc.position is a pointer
	sn.bc = BoxColliderSet(&sn.position, width, height);//setting the collider
	return sn;
}
/*!
@brief create a SnakeNode with the predefined variables
@param x: position on the x coordinate
@param y: position on the y coordinate
@param w: Width of the Node
@param h: height of the Node
@param tickTime: update time for each tick
@return SnakeBody: returns a SnakeBody that has been
					created and a collider done
*//*_________________________________________________________________________*/
struct SnakeBody CreateSnakeBody(float x,float y,float w,float h,float tickTime)
{
	struct SnakeBody sb;
	//hard coded 5 ticks of immunity
	sb.immunity = 5;
	//default size of the list to 4
	sb.list = (struct SnakeNode*)calloc(DEFAULTSNAKELENGTH , sizeof(struct SnakeNode));
	sb.listSize = DEFAULTSNAKELENGTH;
	sb.length = 0;

	sb.bodyWidth = w;
	sb.bodyHeight = h;
	sb.speed = w + h * 0.5f; // average between the width and height
	sb.dir = CP_Vector_Set(1, 0);//default direction to moving right
	//create the head at position x,y
	struct SnakeNode sn = CreateSnakeNode(x,y,w,h);
	sb.list[0] = sn;
	sb.last = &sb.list[0];
	sb.head = &sb.list[0];
	++sb.length;
	
	sb.updateTime = tickTime;
	sb.timer = sb.updateTime;

	return sb;
}
/*!
@brief clears the memory allocated in snakebody
@param sb: hold a list of SnakeNode
*//*_________________________________________________________________________*/
void DeleteSnakeBody(struct SnakeBody* sb)
{
	free(sb->list);//removing memory
}
/*!
@brief Adds a SnakeNode to SnakeBody
@param sb: hold a list of SnakeNode
*//*_________________________________________________________________________*/
void SnakeBodyAddNode(struct SnakeBody* sb)
{
	if (sb->length == sb->listSize)
	{
		SnakeBodyResizeList(sb);
	}
	sb->list[sb->length] = CreateSnakeNode(sb->last->position.x,sb->last->position.y,sb->bodyWidth,sb->bodyHeight);
	sb->list[sb->length].bc.position = &sb->list[sb->length].position;
	sb->last = &sb->list[sb->length];
	++sb->length;
	sb->updateTime *= 0.98f;//game gets 2% faster everytime the snake length increase
}
/*!
@brief Resize the list to contain for containing more SnakeNodes
@param sb: hold a list of SnakeNode
*//*_________________________________________________________________________*/
void SnakeBodyResizeList(struct SnakeBody* sb)
{
	unsigned int newSize = sb->listSize * 2;
	sb->listSize = newSize;
	struct SnakeNode* temp = calloc(newSize , sizeof(struct SnakeNode));
	if (temp != NULL)
	{
		temp = memcpy(temp, sb->list, sb->length * sizeof(struct SnakeNode));
		free(sb->list);
		sb->list = temp;
		sb->last = &temp[sb->length-1];
		sb->head = &temp[0];
		//mem copy only copied the variables //need to redirect pointers
		for (unsigned int i = 0; i < sb->length; ++i)
      		sb->list[i].bc.position = &temp[i].position;
	}
}
/*!
@brief Renders each and everyone of the SnakeNodes
@param sb: hold a list of SnakeNode
*//*_________________________________________________________________________*/
void SnakeBodyRender(struct SnakeBody* sb)
{
	//draw head
	CP_Settings_Fill(CP_Color_Create(100, 0, 0, 255));
	CP_Graphics_DrawRect(sb->head->position.x, sb->head->position.y, sb->bodyWidth, sb->bodyHeight);
	//draw body
	CP_Settings_Fill(CP_Color_Create(0, 100, 0, 255));
	for (unsigned int i = 1; i < sb->length; ++i)
	{
		CP_Graphics_DrawRect(sb->list[i].position.x, sb->list[i].position.y, sb->bodyWidth, sb->bodyHeight);

	}
}
/*!
@brief Resize the list to contain for containing more SnakeNodes
@param sb: hold a list of SnakeNode
@param dt: delta time
*//*_________________________________________________________________________*/
void SnakeBodyUpdate(struct SnakeBody* sb, float dt)
{
	sb->timer -= dt;
	if (sb->timer > 0)
		return;
	else
	{
		--sb->immunity;//5 ticks of immunity 
		sb->timer = sb->updateTime;
	}
	//stores the current and next position
	float currtempx = sb->head->position.x;
	float currtempy = sb->head->position.y;
	float nexttempx = 0;
	float nexttempy = 0;
	sb->head->position.x += sb->dir.x*sb->speed;
	sb->head->position.y += sb->dir.y*sb->speed;
	for (unsigned int i = 1; i < sb->length; ++i)
	{
		//storing it for the next node
		nexttempx = sb->list[i].position.x;
		nexttempy = sb->list[i].position.y;

		//making the node take the previous position of the node before it
		sb->list[i].position.x = currtempx;
		sb->list[i].position.y = currtempy;
		
		//preparing the values for the next node
		currtempx = nexttempx;
		currtempy = nexttempy;
	}
}
/*!
@brief check collision of snake head against its own body
@param sb:contains the values for SnakeNode
@return int:return 1 if collides with itself and 0 if it dosent
*//*_________________________________________________________________________*/
int SnakeBodyCollision(struct SnakeBody* sb)
{
	if (sb->immunity > 0) // if immune do not check collision
		return 0;
	for (unsigned int i = 2; i < sb->length; ++i)//ignore the first 3 nodes it is impossible to touch it
	{
		//direction to the node we checking (normalized)
		CP_Vector normal = CP_Vector_Normalize(CP_Vector_Subtract(sb->list[i].position, sb->head->position));
		//if it collides it should be 0
		float len = CP_Vector_Length(CP_Vector_Subtract(normal,sb->dir));
		if (len < 0.1f)//0.1 just incase
		{
			if (BoxColliderCheckCollision(sb->head->bc,sb->list[i].bc))
				return 1;//collides
		}
	}
	return 0;
}
/*!
@brief check if the direction that the player is trying to move to is viable
@param sb:contains the values for direction
@param direction:the input direction
*//*_________________________________________________________________________*/
void SnakeSetDirection(struct SnakeBody* sb,CP_Vector direction)
{
	CP_Vector v = CP_Vector_Subtract(sb->list[1].position ,sb->head->position);
	v = CP_Vector_Normalize(v);
	if (direction.x == v.x && direction.y == v.y)
		return;
	else
		sb->dir = direction;
}
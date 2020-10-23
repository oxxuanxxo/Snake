#include "SnakeBody.h"
#include "stdlib.h"
#include "stdio.h"
#include "../CProcessing/inc/cprocessing.h"


struct SnakeNode CreateSnakeNode(float x, float y, float width, float height)
{
	struct SnakeNode sn;
	sn.position.x = x;
	sn.position.y = y;
	//bc.position is a pointer
	sn.bc = BoxColliderSet(&sn.position, width, height);
	return sn;
}
struct SnakeBody CreateSnakeBody(float x,float y,float w,float h,float tickTime)
{
	struct SnakeBody sb;

	sb.immunity = 5;//ticks of immunity

	sb.list = (struct SnakeNode*)calloc(DEFAULTSNAKELENGTH , sizeof(struct SnakeNode));
	sb.listSize = DEFAULTSNAKELENGTH;

	sb.length = 0;
	sb.bodyWidth = w;
	sb.bodyHeight = h;
	sb.speed = w;
	sb.dir = CP_Vector_Set(1, 0);
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

void DeleteSnakeBody(struct SnakeBody* sb)
{
	free(sb->list);
}

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
		//mem copy only copied the variables and did not relink the pointers
		for (unsigned int i = 0; i < sb->length; ++i)
      		sb->list[i].bc.position = &temp[i].position;
	}
}

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

void SnakeBodyUpdate(struct SnakeBody* sb, float dt)
{
	sb->timer -= dt;
	if (sb->timer > 0)
		return;
	else
	{
		--sb->immunity;
		sb->timer = sb->updateTime;
	}
	float currtempx = sb->head->position.x;
	float currtempy = sb->head->position.y;
	float nexttempx = 0;
	float nexttempy = 0;
	sb->head->position.x += sb->dir.x*sb->speed;
	sb->head->position.y += sb->dir.y*sb->speed;
	for (unsigned int i = 1; i < sb->length; ++i)
	{
		//generic snake movement(todo change to a more dynamic kind)
		nexttempx = sb->list[i].position.x;
		nexttempy = sb->list[i].position.y;

		sb->list[i].position.x = currtempx;
		sb->list[i].position.y = currtempy;

		currtempx = nexttempx;
		currtempy = nexttempy;
	}
}
int SnakeBodyCollision(struct SnakeBody* sb)
{
	if (sb->immunity > 0)
		return 0;
	for (unsigned int i = 2; i < sb->length; ++i)//ignore the first 3 nodes it is impossible to touch it
	{
		CP_Vector normal = CP_Vector_Normalize(CP_Vector_Subtract(sb->list[i].position, sb->head->position));
		float len = CP_Vector_Length(CP_Vector_Subtract(normal,sb->dir));
		if (len < 0.1f)
		{
			if (BoxColliderCheckCollision(sb->head->bc,sb->list[i].bc))
				return 1;
		}
	}
	return 0;
}
void SnakeSetDirection(struct SnakeBody* sb,CP_Vector direction)
{
	CP_Vector v = CP_Vector_Subtract(sb->list[1].position ,sb->head->position);
	v = CP_Vector_Normalize(v);
	if (direction.x == v.x && direction.y == v.y)
		return;
	else
		sb->dir = direction;
}
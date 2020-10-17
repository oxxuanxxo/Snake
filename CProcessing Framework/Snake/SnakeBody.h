#pragma once
#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "../CProcessing/inc/cprocessing.h"


struct SnakeNode
{
	CP_Vector position;
	//can add other variables for rendering different parts for the body
};

struct SnakeBody
{
	struct SnakeNode* list;
	int listSize;
	int snakeLength;
};
void AddNode(SnakeBody sb, SnakeNode sn);


#endif // !SNAKEBODY_H

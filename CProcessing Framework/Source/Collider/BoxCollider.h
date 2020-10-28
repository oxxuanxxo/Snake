#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "cprocessing.h"

struct BoxCollider
{
	CP_Vector* position;//address of the object position
	float width;		//width of collider
	float height;		//height of collider
};
//creating box collider
struct BoxCollider BoxColliderSet(CP_Vector* pos, float w, float h);
//updating collision
int BoxColliderCheckCollision(struct BoxCollider a, struct BoxCollider b);

#endif // !BOXCOLLIDER_H

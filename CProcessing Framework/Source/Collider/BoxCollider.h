#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H
#include "../../CProcessing/inc/cprocessing.h"

//basic box collider
struct BoxCollider
{
	CP_Vector* position;
	float width;
	float height;
};

struct BoxCollider BoxColliderSet(CP_Vector* pos, float w, float h);
//void BoxColliderCopy(struct BoxCollider old, struct BoxCollider new);

int BoxColliderCheckCollision(struct BoxCollider a, struct BoxCollider b);

#endif // !BOXCOLLIDER_H

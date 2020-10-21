#include "BoxCollider.h"



struct BoxCollider BoxColliderSet(CP_Vector* pos, float w, float h)
{
	struct BoxCollider bc;
	bc.position = pos;
	bc.width = w;
	bc.height = h;
	return bc;
}
int BoxColliderCheckCollision(struct BoxCollider a, struct BoxCollider b)
{
	float aw, ah, bw, bh;
	aw = a.width * 0.5f;
	ah = a.height * 0.5f;
	bw = b.width * 0.5f;
	bh = b.height * 0.5f;
	return ((a.position->x ) >= (b.position->x - bw - aw)) &&
		((b.position->x) >= (a.position->x - aw - bw)) &&
		((a.position->y) >= (b.position->y - bh - ah)) &&
		((b.position->y) >= (a.position->y - ah - bh));
}
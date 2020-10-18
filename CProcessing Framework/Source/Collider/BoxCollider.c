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
	return ((a.position->x + aw) >= (b.position->x - bw)) &&
		((b.position->x + bw) >= (a.position->x - aw)) &&
		((a.position->y + ah) >= (b.position->y - bh)) &&
		((b.position->y + bh) >= (a.position->y - ah));
}
#include "BoxCollider.h"
/*!
@file BoxCollider.c
@author Leong Jun Xiang(junxiang.leong)
@date 21/10/2020
@brief contains functions for check a box to box collision
*//*_________________________________________________________________________*/


/*!
@brief Set a box collider with the define parameters
@param pos the address of the item attatched with the boxcollider struct
@param w width of the collider
@param h height of the collider
@return struct BoxCollider which would be stored by the object
*//*_________________________________________________________________________*/
struct BoxCollider BoxColliderSet(CP_Vector* pos, float w, float h)
{
	struct BoxCollider bc;
	bc.position = pos;
	bc.width = w;
	bc.height = h;
	return bc;
}
/*!
@brief Updates the collision between 2 boxcolliders
@param a first box collider
@param b second box collider
@return int:return 1 when collide and 0 if it dosent
*//*_________________________________________________________________________*/
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
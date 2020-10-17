#ifndef _CAMERA_H
#define _CAMERA_H

#include "CProcessing.h"

struct Camera
{
	CP_Vector position;
	CP_Vector scale; // the bigger the camera scale, the bigger the "view range". Hence objects will be seen as smaller.
	float rotation;

	CP_Matrix transfrom;
	CP_Matrix viewMatrix; //this matrix handles world to camera space conversion
	CP_Matrix projectionMatrix; //this matrix handles camera to screen space conversion
	CP_Matrix VPMatrix; //matrix containing projection*view
};

void Camera_UpdateProjection(struct Camera* camera);
void Camera_Init(struct Camera* camera);
void Camera_Update(struct Camera* camera);

CP_Vector Camera_ScreenToWorldSpace(struct Camera* camera, CP_Vector screenCoords);
CP_Vector Camera_WorldToScreenSpace(struct Camera* camera, CP_Vector worldCoords);

void Camera_Input(struct Camera* camera);

#endif
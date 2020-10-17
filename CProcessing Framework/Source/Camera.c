#include "Camera.h"



void Camera_UpdateProjection(struct Camera* camera)
{
	//this matrix handles the conversion from camera space to screen space.
	CP_Matrix translate = CP_Matrix_Translate(CP_Vector_Set(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f));
	CP_Matrix yReverse = CP_Matrix_Scale(CP_Vector_Set(1.0f,-1.0f));//this matrix will flip the y-axis
	//camera->projectionMatrix = translate;
	camera->projectionMatrix = CP_Matrix_Multiply(translate, yReverse);
}

void Camera_Init(struct Camera* camera)
{
	camera->position = CP_Vector_Set(0.0f, 0.0f);
	camera->scale = CP_Vector_Set(1.0f, 1.0f);
	//camera->scale = CP_Vector_Set(50.0f, 50.0f);

	//camera->scale.y *= -1.0f; // flips the y axis (screen space y is downwards)
	camera->viewMatrix = CP_Matrix_Identity();
	camera->rotation = 0.0f;

	
	Camera_UpdateProjection(camera);


}


void Camera_Update(struct Camera* camera)
{
	CP_Matrix scale = CP_Matrix_Scale((camera->scale));
	

	// move to camera position, offset based on left of screen.
	CP_Matrix translate = CP_Matrix_Translate(CP_Vector_Set(camera->position.x,camera->position.y)); //y-axis is inverted here to prevent scaling from being inverted.
	
	CP_Matrix rotate = CP_Matrix_Rotate(camera->rotation);

	camera->transfrom = CP_Matrix_Multiply(translate, CP_Matrix_Multiply(rotate,scale));
	
	camera->viewMatrix = CP_Matrix_Inverse(camera->transfrom);

	camera->VPMatrix = CP_Matrix_Multiply(camera->projectionMatrix, camera->viewMatrix);

	CP_Settings_ApplyMatrix(camera->VPMatrix);
}


CP_Vector Camera_ScreenToWorldSpace(struct Camera* camera, CP_Vector screenCoords)
{
	return CP_Vector_MatrixMultiply(CP_Matrix_Inverse(camera->VPMatrix), screenCoords);
}

CP_Vector Camera_WorldToScreenSpace(struct Camera* camera, CP_Vector worldCoords)
{
	return CP_Vector_MatrixMultiply(camera->VPMatrix,worldCoords);
}

void Camera_Input(struct Camera* camera)
{
	float cameraSpeed = 200.0f;
	float cameraScaleSpeed = 1.0f;
	float dt = CP_System_GetDt();
	if (CP_Input_KeyDown(KEY_UP))
	{
		camera->position.y += cameraSpeed * dt;
	}
	if (CP_Input_KeyDown(KEY_DOWN))
	{
		camera->position.y -= cameraSpeed * dt;
	}
	if (CP_Input_KeyDown(KEY_RIGHT))
	{
		camera->position.x += cameraSpeed * dt;
	}
	if (CP_Input_KeyDown(KEY_LEFT))
	{
		camera->position.x -= cameraSpeed * dt;
	}

	if (CP_Input_KeyDown(KEY_I))
	{
		camera->scale = CP_Vector_Add(camera->scale, CP_Vector_Set(cameraScaleSpeed * dt, cameraScaleSpeed * dt));
	}
	if (CP_Input_KeyDown(KEY_O))
	{
		camera->scale = CP_Vector_Add(camera->scale, CP_Vector_Set(-cameraScaleSpeed * dt, -cameraScaleSpeed * dt));
	}
}
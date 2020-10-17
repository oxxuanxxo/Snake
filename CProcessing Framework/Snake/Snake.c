#include "Snake.h"
#include "../CProcessing/inc/cprocessing.h"



void snake_init()
{
	bg = CP_Color_Create(0, 0, 0, 255);
}
void snake_update()
{
	snake_gameupdate();
	snake_inputs();
	snake_render();
}
void snake_gameupdate(void)
{

}
void snake_inputs(void)
{
	if (CP_Input_KeyDown(KEY_ESCAPE))//press esc to terminate app
	{
		CP_Engine_Terminate();
	}
}
void snake_render(void)
{
	CP_Settings_Background(bg);//set bg to black and works as a clear buffer
	CP_Graphics_DrawRect(100.0f, 100.0f, 50.0f, 50.0f);

}


void snake_exit()
{

}
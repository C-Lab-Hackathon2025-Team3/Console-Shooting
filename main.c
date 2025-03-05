#include "consolGL.h"
#include "console_screen.h"
#include <conio.h>
#define SCREEN_WIDTH 100
#define SCREEN_HEGITH 50

float dx = 0;
float dy = 0;
float angle_y = 0.F;
float angle_z = 0.F;
float angle_x = 0.F;
float camAngle = 0.F;
vec3_t eye = { 0.F , 50.F , -100.F };
vec3_t center = { 0.F , 0.F  , 0.F };
vec3_t up = { 0.F , 1.F , 0.F };


void eventCall()
{

	int key = getch();
	if (key == 'w')
		dy += 1.F;
	else if (key == 's')
		dy -= 1.F;
	else if (key == 'a')
		dx -= 1.F;
	else if (key == 'd')
		dx += 1.F;
	else if (key == 'q')
		angle_y += -0.1F;
	else if (key == 'e')
		angle_y += +0.1F;
	else if (key == 'r')
	{
		camAngle += 0.1F;
	}
	

	vec3_t rotate_v = { 0.F , 1.F , 0.F };
	
	vec3_t translate = {dx , dy , 0};

	rotate_object(angle_y , rotate_v);

	translate_object(translate);

	eye.x = sin(camAngle);
	eye.z = -cos(camAngle);
	//view_cam(eye, center, up);

}

int main(void)
{

	vec4_t tri[3] = {
			{ -1.F , 0.F ,0.F ,1.F},
			{ 0.F ,  1.F ,0.F ,1.F},
			{ 1.F , 0.F,0.F ,1.F},
	};

	vec4_t cube[8] = {

		{ -1.F  , -1.F ,-1.F ,0.1},
		{ -1.F  , -1.F ,1.F ,0.1F},
		{ -1.F  , 1.F ,-1.F ,1.F},
		{ -1.F  , 1.F ,1.F ,1.F},

		{ 1.F  , -1.F ,-1.F ,0.1F},
		{ 1.F  , -1.F ,1.F ,0.1F},
		{ 1.F  , 1.F ,-1.F ,1.F},
		{ 1.F  , 1.F ,1.F ,1.F},
	};


	int indices[36] = {
		5,4,0,
		0,1,5,

		7,5,1,
		1,3,7,

		6,7,3,
		3,2,6,

		4,6,2,
		2,0,4,

		3,1,0,
		0,2,3,

		6,4,5,
		5,7,6
	};

	vec4_t cube_vertex_buf[36];

	for (int idx = 0; idx < 36; idx++)
	{
		cube_vertex_buf[idx] = cube[indices[idx]];
	}
	init_screen(SCREEN_WIDTH, SCREEN_HEGITH);
	
	
	
	scale_object((vec3_t) {10.F  ,10.F ,10.F});
	view_cam(eye, center, up);

	while (1)
	{
		set_vertex_array(tri);
		draw_vertex_array(DRAW_LINE_TRIANGLES, 0, 3);

		draw_screen();
		clear_screen();
		eventCall();

		
	}


	release_screen();
	return 0;
}
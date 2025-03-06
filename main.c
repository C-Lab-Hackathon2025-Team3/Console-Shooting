#include "consolGL.h"
#include "console_screen.h"
#include <conio.h>
#define SCREEN_WIDTH 100
#define SCREEN_HEGITH 100

float dx = 0;
float dy = 0;
float dz = 0;
float angle_y = 0.F;
float angle_z = 0.F;
float angle_x = 0.F;
float camAngle = 0.F;
vec3_t eye = { 0.F , 10.F , -20.F };
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
		dz += 1.F;
	}
	
	

	vec3_t rotate_v = { 0.F , 1.F , 0.F };
	
	vec3_t translate = {dx , dy , dz};

	rotate_object(angle_y , rotate_v);

	translate_object(translate);

	eye.x = sin(camAngle);
	eye.z = -cos(camAngle);
	//view_cam(eye, center, up);

}

int main(void)
{

	vec4_t tri[3] = {
			{ -1.F  , 0.F ,0.F ,1.F},
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
		//p1 , p2 , p3
		5,4,0,
		5,0,1,

		7,5,1,
		7,1,3,

		6,7,3,
		6,3,2,

		4,6,2,
		4,2,0,

		3,1,0,
		3,0,2,

		6,4,5,
		6,5,7
	};

	vec4_t cube_vertex_buf[36];

	for (int idx = 0; idx < 36; idx++)
	{
		cube_vertex_buf[idx] = cube[indices[idx]];
	}
	init_screen(SCREEN_WIDTH, SCREEN_HEGITH);
	
	
	
	scale_object((vec3_t) {15.F ,15.F ,15.F});
	view_cam(eye, center, up);
	projection_screen((float)SCREEN_WIDTH/2, -(float)SCREEN_WIDTH / 2.F ,(float)SCREEN_HEGITH/2.F, -(float)SCREEN_HEGITH/2.F, -35.F, +100.F);

	while (1)
	{
		set_vertex_array(cube_vertex_buf);
		translate_object((vec3_t) { -30.F, 0.F, 0.F });
		draw_vertex_array(DRAW_TRIANGLES, 0, 36);

		translate_object((vec3_t) {30.F , 0.F , 0.F});
		draw_vertex_array(DRAW_TRIANGLES, 0, 36);


		draw_screen();
		clear_screen();
		eventCall();

		
	}


	release_screen();
	return 0;
}
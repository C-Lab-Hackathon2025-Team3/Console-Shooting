#include "consolGL.h"
#include "console_screen.h"
#include "z_buffer_screen.h"
#include "draw_sphere.h"
#include "model_object.h"
#include <math.h>
#include <conio.h>
#define SCREEN_WIDTH 200
#define SCREEN_HEGITH 200


float g_cam_angle_x = 0.785398F;
float g_cam_angle_y = 0.785398F;
float g_cam_angle_z = 0.785398F;
float cam_r = 5.F;

vec3_t g_cam_eye = { 0.F , 5.F , -10.F };
vec3_t g_cam_center = { 0.F , 0.F  , 0.F };
vec3_t g_cam_up = { 0.F , 1.F , 0.F };

object_t g_sphere;
object_t g_spike_sphere;


void eventCall()
{

	int key = getch();
	if (key == 'w')
		g_sphere.pos.y += 1.F;
	else if (key == 's')
		g_sphere.pos.y -= 1.F;
	else if (key == 'a')
		g_sphere.pos.x -= 1.F;
	else if (key == 'd')
		g_sphere.pos.x += 1.F;
	else if (key == 'i')
		g_spike_sphere.pos.y += 1.F;
	else if (key == 'k')
		g_spike_sphere.pos.y -= 1.F;
	else if (key == 'j')
		g_spike_sphere.pos.x -= 1.F;
	else if (key == 'l')
		g_spike_sphere.pos.x += 1.F;
	else if (key == 'q')
	{
		g_sphere.angle += 0.1F;
		g_spike_sphere.angle += -0.1F;
	}
	else if (key == 'e')
	{
		g_sphere.angle += -0.1F;
		g_spike_sphere.angle += 0.1F;
	}


}

void init_program(void);

int main(void)
{
	init_program();
	g_sphere.scale = (vec3_t){10.F , 10.F , 10.F};
	g_spike_sphere.scale = (vec3_t){ 10.F , 10.F , 10.F };

	g_sphere.pos = (vec3_t){5.F , 0.F , 0.F};
	g_spike_sphere.pos = (vec3_t){-5.F , 0.F , 0.F };
	while (1)
	{
		
		draw_object(&g_sphere);
		draw_object(&g_spike_sphere);
		draw_screen();
		
		clear_depth_buffer();
		clear_screen();
		eventCall();

		
	}

	release_object(&g_sphere);
	release_object(&g_spike_sphere);
	release_depth_buffer();
	release_screen();
	return 0;
}

void init_program(void)
{
	init_screen(SCREEN_WIDTH, SCREEN_HEGITH);
	init_depth_buffer(SCREEN_WIDTH, SCREEN_HEGITH);


	view_cam(g_cam_eye, g_cam_center, g_cam_up);
	projection_screen(-(float)SCREEN_WIDTH / 4.F, (float)SCREEN_WIDTH / 4.F, -(float)SCREEN_HEGITH / 4.F, (float)SCREEN_HEGITH / 4.F, -80.F, 80.F);

	load_file_object(&g_sphere, "sphere_model.object");
	load_file_object(&g_spike_sphere, "spike_sphere_model.object");
}
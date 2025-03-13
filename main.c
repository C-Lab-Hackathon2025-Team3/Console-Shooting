#include "consolGL.h"
#include "console_screen.h"
#include "z_buffer_screen.h"
#include "draw_sphere.h"
#include "model_object.h"
#include <math.h>
#include <conio.h>
#include <time.h>
#if defined(__APPLE__)
#include <termios.h>
#include <fcntl.h>
#else
#include <windows.h>
#endif

#define SCREEN_WIDTH 200
#define SCREEN_HEGITH 200
#define Y_MAX (100)
#define Y_MIN (-30.F)
#define PI (3.1415926535F)

#if defined(__APPLE__)
struct termios g_oldt, g_newt;

void init_keyboard() {
	tcgetattr(STDIN_FILENO, &g_oldt);
	g_newt = g_oldt;
	g_newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &g_newt);

	int g_flags = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

void reset_keyboard() {
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
#endif

float g_sign[2] = {-1.F , 1.F};
float g_cam_angle_x = 0.785398F;
float g_cam_angle_y = 0.785398F;
float g_cam_angle_z = 0.785398F;
float cam_r = 5.F;

vec3_t g_cam_eye = { 0.F , 5.F , -10.F };
vec3_t g_cam_center = { 0.F , 0.F  , 0.F };
vec3_t g_cam_up = { 0.F , 1.F , 0.F };

object_t g_sphere;
object_t g_spike_sphere;

object_t g_player;
object_t g_enemy[9];
float g_accelate[9] = { 0.F, };

clock_t g_start_time;
clock_t g_current_time;
float g_elapsed_time = 0;


void eventCall()
{



#if defined(__APPLE__)
	int key = getch();

	if ((key == 'a' || key == 'A') && (g_player.pos.x > -40.F))
		g_player.pos.x -= 1.F;
	else if ((key == 'd' || key == 'D') && (g_player.pos.x < 40.F))
		g_player.pos.x += 1.F;

#else
	if (_kbhit()) {
		int key = getch();

		if ((key == 'a' || key == 'A') && (g_player.pos.x > -40.F))
			g_player.pos.x -= 2.F;
		else if ((key == 'd' || key == 'D') && (g_player.pos.x < 40.F))
			g_player.pos.x += 2.F;
	}
#endif

}

void init_program(void);

int main(void)
{
	init_program();
	g_accelate[rand() % 9] = 0.5F;

	while (1)
	{
		g_current_time = clock();

		g_elapsed_time = (float)(g_current_time - g_start_time) / CLOCKS_PER_SEC * 1000;
		g_player.angle = g_elapsed_time/1000.F;
		draw_object(&g_player);
		
		srand(time(NULL));

		for (size_t i = 0; i < 9; i++)
		{
			g_enemy[i].angle = g_elapsed_time / 1000.F * g_sign[i % 2];
			g_enemy[i].pos.y -=(g_elapsed_time / 10000.F) * g_accelate[i];
			if (g_enemy[i].pos.y < Y_MIN) 
			{
				g_enemy[i].pos.y = Y_MAX + 20;
				g_accelate[i] = 0;
				g_accelate[rand() % 9] = 0.5F;
			}

			draw_object(g_enemy + i);
		}




		draw_screen();

		

		clear_depth_buffer();
		clear_screen();
		eventCall();

	
	}

#if defined(__APPLE__)
	reset_keyboard(); 
#endif

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

	load_file_object(&g_player, "sphere_model.object");
	g_player.scale = (vec3_t){ 10.F , 10.F ,10.F };
	g_player.pos = (vec3_t){ 0.F , Y_MIN , 0.F };
	for (size_t i = 0; i < 9; i++)
	{
		load_file_object(&g_enemy[i], "spike_sphere_model.object");
		g_enemy[i].scale = (vec3_t){ 5.F , 5.F ,5.F };
		g_enemy[i].pos = (vec3_t){ -40.F + (float)i * 10.F , Y_MAX + 20 , 0.F };
	}

	g_start_time = clock();
	#if defined(__APPLE__)
		init_keyboard();
	#endif
}
#include <math.h>
#include "def.h"
#include "console_screen.h"
#include "convert_screen.h"
#include "polygon.h"

int main(void)
{
	init_screen(40, 20);
	
	draw_point(0, 0, ASCII_BRIGHTNESS[BIRGHTNESS_RANGE / 2]);
	draw_point(0.5, 0.5, ASCII_BRIGHTNESS[BIRGHTNESS_RANGE / 2]);
	draw_point(0.5, -0.5, ASCII_BRIGHTNESS[BIRGHTNESS_RANGE / 2]);
	draw_point(-0.5, 0.5, ASCII_BRIGHTNESS[BIRGHTNESS_RANGE / 2]);
	draw_point(-0.5, -0.5, ASCII_BRIGHTNESS[BIRGHTNESS_RANGE / 2]);
	draw_point(-1, -1, ASCII_BRIGHTNESS[BIRGHTNESS_RANGE / 2]);
	draw_point(-1, -0.5F, ASCII_BRIGHTNESS[BIRGHTNESS_RANGE / 2]);
	
<<<<<<< Updated upstream
=======
	
	scale_object((vec3_t) {10.F  ,10.F ,10.F});
	view_cam(eye, center, up);

	while (1)
	{
		set_vertex_array(cube_vertex_buf);
		draw_vertex_array(DRAW_LINE_TRIANGLES, 0, 36);

		draw_screen();
		clear_screen();
		eventCall();

		
	}

>>>>>>> Stashed changes

	draw_screen();
	release_screen();
	return 0;
}

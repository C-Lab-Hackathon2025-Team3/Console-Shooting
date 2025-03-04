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
	

	draw_screen();
	release_screen();
	return 0;
}

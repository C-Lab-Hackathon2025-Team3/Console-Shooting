#include "console_screen.h"
#include "convert_screen.h"

void convert_screen_coordinate(const float x, const float y, int* const out_screenX, int* const out_screenY) {
	int width = get_screen_width();
	int height = get_screen_height();

	*out_screenX = (int)((x + 1) / 2 * (width - 1));
	*out_screenY = (int)((1 - y) / 2 * (height - 1));
}

void draw_point(float x, float y, char pixel) {
	int screenX, screenY;
	convert_screen_coordinate(x, y, &screenX, &screenY);
	push_pixel(pixel, screenX, screenY);
}